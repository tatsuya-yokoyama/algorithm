#include <iostream>

using namespace std;

int n;
int A[110][110];
int d[110];
int f[110];
string color[110];
int t = 0;

void dfs_visit(int s) {
  d[s] = ++t;
  color[s] = "GRAY";
  for (int v = 0; v < n; v++) {
    if (A[s][v] == 0) continue;
    if (color[v] == "WHITE") {
      dfs_visit(v);
    }
  }
  color[s] = "BLACK";
  f[s] = ++t;
}

void dfs() {
  // 初期化
  for (int i = 0; i < n; i++) {
    color[i] = "WHITE";
  }
  // 未訪問のuを始点として深さ優先探索
  for (int u = 0; u < n; u++) {
    if (color[u] == "WHITE") {
      dfs_visit(u);
    }
  }
}
int main() {

  // cin
  cin >> n;
  int u, k, v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      A[u-1][v-1] = 1;
    }
  }

  dfs();

  // print
  for (int i = 0; i < n; i++) {
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
}
