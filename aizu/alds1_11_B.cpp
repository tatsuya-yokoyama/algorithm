#include <iostream>
#include <stack>

using namespace std;

int n;
bool A[110][110];
int d[110];
int f[110];
int t = 0;
string color[110];

int next(int u) {
  for (int v = 0; v < n; v++) {
    if (v == u) {
      continue;
    } else {
      if (A[u][v] && color[v] == "WHITE") {
        return v;
      }
    }
  }
  return -1;
}

void dfs(int r) {
  stack<int> S;
  color[r] = "GRAY";
  d[r] = ++t;
  S.push(r);

  while(!S.empty()) {
    int u = S.top();
    int v = next(u);
    if (v != -1) {
      if (color[v] == "WHITE") {
        color[v] = "GRAY";
        d[v] = ++t;
        S.push(v);
      }
    } else {
      S.pop();
      color[u] = "BLACK";
      f[u] = ++t;
    }
  }

}

int main() {

  // 隣接行列を初期化
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = false;
    }
  }
  // 隣接行列に書き込み & ノードをwhiteに
  for (int i = 0; i < n; i++) {
    int u, k, v;
    cin >> u >> k;
    u--;
    color[u] = "WHITE";
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;
      A[u][v] = true;
    }
  }

  // dfs
  for (int u = 0; u < n; u++) {
    if (color[u] == "WHITE") {
      dfs(u);
    }
  }

  // cout << "---------" << endl;
  // print
  for (int i = 0; i < n; i++) {
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }

}
