#include <iostream>
#include <queue>

using namespace std;

int n;
bool A[110][110];
int d[110];
int f[110];
int t = 0;
string color[110];
queue<int> q;

// void dfs(int u) {
//   color[u] = "GRAY";
//   d[u] = ++t;
//   for (int v = 0; v < n; v++) {
//     if (A[u][v] && color[v] == "WHITE") {
//       // cout << "u:" << u+1 << " to " << v+1 << endl;
//       dfs(v);
//     }
//   }
//   color[u] = "BLACK";
//   f[u] = ++t;
// }

int main() {


  // 隣接行列を初期化
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = false;
    }
  }
  // 距離初期化
  for (int i = 0; i < 110; i++) {
    d[i] = -1;
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

  q.push(0);
  d[0] = 0;
  color[0] = "GRAY";
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < n; v++) {
      if (A[u][v] && color[v] == "WHITE") {
        q.push(v);
        d[v] = d[u] + 1;
        color[v] = "GRAY";
        // cout << "from:" << u+1 << ", to:" << v+1 << endl;
      }
    }
    color[u] = "BLACK";
  }

  // cout << "---------" << endl;
  // print
  for (int i = 0; i < n; i++) {
    cout << i+1 << " " << d[i] << endl;
  }

}
