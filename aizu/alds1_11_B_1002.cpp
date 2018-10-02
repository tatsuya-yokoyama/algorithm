#include <iostream>

using namespace std;

int n;
int A[110][110];
int d[110];
int f[110];
int t = 0;

int next(int u) {
  for (int v = 0; v < n; v++) {
    if (A[u][v] == 1 && d[v] == 0) {
      return v;
    }
  }
  return -1;
}

void dfs_visit(int u) {
  d[u] = ++t;
  int v = next(u);
  while(v != -1) {
    dfs_visit(v);
    v = next(u);
  }
  f[u] = ++t;
}

void dfs() {
  // 初期化
  for (int i = 0; i < n; i++) {
    d[i] = 0;
  }
  for (int u = 0; u < n; u++) {
    if (d[u] == 0) {
      dfs_visit(u);
    }
  }
}

int main() {
    cin >> n;
    int u, k, v;
    for (int i = 0; i < n; i++) {
      cin >> u >> k;
      for (int j = 0; j < k; j++) {
        cin >> v;
        A[u-1][v-1] = 1;
      }
    }
    dfs();

    // answer
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
}
