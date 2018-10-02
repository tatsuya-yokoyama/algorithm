#include <iostream>
#include <queue>
#define NIL -1

using namespace std;

int A[100010][100010];
int d[100010];
int n, m;

int bfs(int s, int t) {
  queue<int> q;
  // 距離初期化
  for (int i = 0; i < n; i++) d[i] = NIL;
  q.push(s);
  d[s] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    if (u == s) {
      cout << "find s:" << s << ", t:" << t << endl;
      return d[u];
    }
    for (int v = 0; v < n; v++) {
      if (A[u][v] == 1 && d[v] == NIL) {
        q.push(v);
        d[v] = d[u] + 1;
      }
    }
  }
  return NIL;
}

int main() {
  cin >> n >> m;
  int A[n][n];
  int s, t;

  // 初期化
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    A[s][t] = 1;
  }

  // 質問
  int q;
  cin >> q;
  cout << "number of question:" << q << endl;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (bfs(s, t) != -1) {
      cout << "no."<< i << ", yes" << endl;
    } else {
      cout << "no."<< i << ", no" << endl;
    }
  }
}
