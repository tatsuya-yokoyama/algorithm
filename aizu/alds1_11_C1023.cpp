#include <iostream>
#include <queue>

using namespace std;

int n;
int A[110][110];
int d[110];
queue<int> Q;

void bfs(int s) {
  Q.push(s);
  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int v = 0; v < n; v++) {
      if (A[u][v] == 1 && d[v] == -1) {
        Q.push(v);
        d[v] = d[u] + 1;
        // cout << "u:" << u << " -> v:" << v << ", d[u]" << d[u] << endl;
      }
    }
  }
}

int main() {
    cin >> n;
    int u, k, v;
    for (int i = 0; i < n; i++) {
      // 一緒に初期化しちゃう
      d[i] = -1;
      cin >> u >> k;
      for (int j = 0; j < k; j++) {
        cin >> v;
        A[u-1][v-1] = 1;
      }
    }
    // bfs
    d[0]= 0;
    bfs(0);

    // print
    for (int i = 0; i < n; i++) {
      cout << i+1 << " " << d[i] << endl;
    }
}
