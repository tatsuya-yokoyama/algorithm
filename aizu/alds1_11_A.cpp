#include <iostream>

using namespace std;

int main() {
  // 初期化
  int n;
  cin >> n;
  int a[101][101];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      int u_a;
      cin >> u_a;
      u_a--;
      // cout << "u:" << u << ", u_a" << u_a << endl;
      a[u][u_a] = 1;
    }
  }
  // cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j];
      if (j < n-1) {
         cout << " ";
      }
    }
    cout << endl;
  }
}
