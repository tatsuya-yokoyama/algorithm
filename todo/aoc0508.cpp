#include <iostream>
#include <stack>

using namespace std;

int n;
int A[110][110];
int d[110];

void dfs(int u, int d_u) {
  d[u] = d_u;
  for (int v = 1; v <= n; v++) {
    // cout << u << " -> " << v << ", A[u][v]:" << A[u][v] << ", d:" << d[v] << endl;
    // if (u == 2 && v == 7 && A[u][v] == 1 && d[v] == -1) {
    //   cout << "[LOG]: " << A[u][v] << ", d:" << d[v] << endl;
    // }
    if (A[u][v] == 1 && d[v] == -1) {
      // cout << u << " -> " << v << ", d:" << d_u << " -> " << d_u+1 << endl;
      dfs(v, d_u+1);
    }
  }
}

int main() {
  int can_conitnue = true;
  while(can_conitnue) {
    cin >> n;
    if (n == 0) {
      break;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        A[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      int u, v;
      cin >> u >> v;
      A[u][v] = 1;
      A[v][u] = 1;
    }
    int d_max = 0;
    for (int s = 1; s <= n; s++) {
      for (int i = 1; i <= n; i++) {
        d[i] = -1;
      }
      // cout << endl;
      // cout << "[from]" << s << endl;
      dfs(s, 0);
      for (int i = 1; i <= n; i++) {
        // cout << "i:" << i << ", d[i]:" << d[i] << endl;
        d_max = max(d_max, d[i]);
      }
      // cout << "d_max:" << d_max << " at " << s << endl;
    }
    cout << d_max+1 << endl;
  }

}
