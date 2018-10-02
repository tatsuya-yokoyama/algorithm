#include <iostream>
#include <stack>

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
  stack<int> S;
  S.push(u);
  d[u] = ++t;
  while(!S.empty()) {
    int u = S.top();
    int v = next(u);
    // cout << "u:" << u << " -> v:" << v << endl;
    // まだ隣に行ける場合
    if (v != -1) {
      S.push(v);
      d[v] = ++t;
    } else {
      // もう隣に行けない場合
      S.pop();
      f[u] = ++t;
    }
  }
}

void dfs() {
  // 初期化
  for (int i = 0; i < n; i++) {
    d[i] = 0;
    f[i] = 0;
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
