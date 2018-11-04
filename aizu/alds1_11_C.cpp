#include <iostream>
#include <queue>

using namespace std;
const int NIL = -1;

int n;
int A[101][101];
int d[101];

void bfs(int s) {
  queue<int> q;
  q.push(s);
  d[s] = 0;

  int u;
  while(!q.empty()) {
    u = q.front(); q.pop();
    for (int v = 0; v < n; ++v) {
      if (A[u][v] == 1 && d[v] == NIL) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  
  cin >> n;
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      A[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    d[i] = NIL;
  }

  int u, v;
  int k;
  for (int i = 0; i < n; ++i) {
    cin >> u >> k;
    for (int j = 0; j < k; ++j) {
      cin >> v;
      A[u-1][v-1] = 1;
    }
  }

  bfs(0);

  for (int i = 0; i < n; ++i) {    
    cout << i+1 << " " << d[i] << endl;
  }
}