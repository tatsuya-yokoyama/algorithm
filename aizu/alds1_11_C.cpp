#include <iostream>
#include <queue>
#define NIL -1
#define N 110

using namespace std;

bool A[N][N];
int d[N];
int n;

void bfs(int s) {
  queue<int> q;
  // 距離初期化
  for (int i = 0; i < N; i++) d[i] = NIL;
  q.push(s);
  d[s] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for (int v = 0; v < n; v++) {
      if (A[u][v] && d[v] == NIL) {
        q.push(v);
        d[v] = d[u] + 1;
        // cout << "from:" << u+1 << ", to:" << v+1 << endl;
      }
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
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;
      A[u][v] = true;
    }
  }

  // bfs
  bfs(0);

  // print
  for (int i = 0; i < n; i++) {
    cout << i+1 << " " << d[i] << endl;
  }

}
