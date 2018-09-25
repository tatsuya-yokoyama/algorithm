#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;
  int A[110][110];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int u, k, v;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      A[u-1][v-1] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j) cout << ' ';
      cout << A[i][j];
    }
    cout << endl;
  }
}
