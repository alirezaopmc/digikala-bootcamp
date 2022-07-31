/** Jadval
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>

using namespace std;

bool DEBUG = false;
#define _(x) if (DEBUG) { x }

vector<vector<int>> grid;
vector<vector<bool>> vis;

int n;
bool isDn, isUp;

void dfs(int i, int j) {
  _( cout << "DFS =( i: " << i << " j: " << j << endl; )
  vis[i][j] = true;

  for(int di=-1; di<=+1; di++) {
    for(int dj=-1; dj<=+1; dj++) {
      if (di == 0 && dj == 0) continue;

      if(i+di >= 0 && i+di < n && j+dj >= 0 && j+dj < n) {
        
        if (grid[i][j] > grid[i+di][j+dj]) {
          isDn = false;
        }
        if (grid[i][j] < grid[i+di][j+dj]) {
          isUp = false;
        }
        if (grid[i][j] == grid[i+di][j+dj] && ! vis[i+di][j+dj]) {
          _( cout << " |=> " << i+di << " " << j+dj << endl; )
          dfs(i+di, j+dj);
        }
      }
    }
  }
}

int main() {
  cin >> n;

  grid.assign(n, vector<int>(n));
  vis.assign(n, vector<bool>(n, false));


  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> grid[i][j];
    }
  }

  int upCnt = 0;
  int dnCnt = 0;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      isUp = true;
      isDn = true;

      if (! vis[i][j]) dfs(i, j);
      else continue;

      if (isDn) {
        _( cout << "Down" << endl; )
        dnCnt++;
      }

      if (isUp) {
        _( cout << "Up" << endl; )
        upCnt++;
      }
    }
  }

  cout << upCnt << " " << dnCnt << endl;
}
