/* Mosaferat
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1000;
const int MAXN = N * 2;
int n;

typedef struct point {
  int x;
  int y;
} point;

/**
 * DSU Optmization:
 *  Size-in-Par
 *  Path Compression
 */
vector<int> par; // DSU Parents
vector<point> points; // Points

void init() {
  par.assign(MAXN, -1); // Roots keep negative of size
  points.resize(n);
}

int find(int u) {
  int root = u;
  
  // Path Compression
  while(par[root] >= 0) {
    root = par[root];
  }

  while(par[u] >= 0) {
    par[u] = root;
    u = par[u];
  }

  return root;
}

int size(int u) {
  return -par[find(u)];
}

void merge(int u, int v) {
  int pu = find(u);
  int pv = find(v);

  if (pu == pv) return;

  if (size(u) > size(v)) {
    par[pu] += par[pv];
    par[pv] = pu;
  } else {
    par[pv] += par[pu];
    par[pu] = pv;
  }
}

void mergePoint(point p) {
  int xIndex = p.x-1;
  int yIndex = N + p.y-1;

  merge(xIndex, yIndex);
}

int findPoint(point p) {
  return find(p.x-1);
}

int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);


  cin >> n;

  init();

  for(int i=0; i<n; i++) {
    int x, y;

    cin >> points[i].x;
    cin >> points[i].y;

    mergePoint(points[i]);
  }


/*
  string s;
  while(true) {
    cin >> s;

    if (s == "exit") break;
    else if (s == "find") {
      int u;
      cin >> u;
      cout << find(u) << endl;
    }
    else if (s == "merge") {
      int u, v;
      cin >> u >> v;
      merge(u, v);
    }
  }

  return 0;
*/
  set<int> st;

  for(auto p: points) {
    st.insert(findPoint(p));
  }

  cout << (st.size()-1) << endl;
}
