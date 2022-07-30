/** Padeshah
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef uint State;

map<State, bool> V;
map<State, int> H;

int n;

int getAt(State state, int i) {
  return (state >> (3 * i)) & 7;
}

void setAt(State &state, int i, int value) {
  State mask = 7 << (3 * i);
  state &= ~mask;
  state |= (value << (3 * i));
}

void swapAt(State &state, int i, int j) {
  State temp = getAt(state, i);
  setAt(state, i, getAt(state, j));
  setAt(state, j, temp);
}

State resultState(State state, int action) {
  for(int i=0; i<(action+1)/2; i++) {
    swapAt(state, i, action-i);
  }
  return state;
}

/*
int getSize(State state) {
  return getAt(state, 8);
}
*/

State build(int *nums) {
  State s = 0;
  for(int i=0; i<n; i++) {
    setAt(s, i, nums[i]);
  }
//  setAt(s, 8, n);
  return s;
}

void expand(State s, queue<State> &q) {
  for(int i=0; i<n; i++) {
    State adjState = resultState(s, i);

    if (! V[adjState]) {
      q.push(adjState);
      V[adjState] = true;
      H[adjState] = H[s] + 1;
    }
  }
}

bool isGoal(State s) {
  for(int i=0; i<n; i++) {
    if (getAt(s, i) != i) return false;
  }
  return true;
}

int bfs(State s) {
  queue<State> q;
  q.push(s);
  V[s] = true;
  H[s] = 0;

  while(! q.empty()) {
    State u = q.front();

    if (isGoal(u)) return H[u];

    q.pop();

    expand(u, q);
  }

  return -1;
}

int main() {
  cin >> n;

  int *arr = new int[n];

  for(int i=0; i<n; i++) {
    cin >> arr[i];
    arr[i]--;
  }
  
  State s = build(arr);

  cout << bfs(s) << endl;
}
