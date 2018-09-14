#include <iostream>

using namespace std;

int dp[1010][1010];

int lcs(string X, string Y) {
  int m = X.size();
  int n = Y.size();
  X = ' ' + X;
  Y = ' ' + Y;
  // 初期化
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (X[i] == Y[j]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
      }
    }
  }
  return dp[m][n];
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string X, Y;
    cin >> X >> Y;
    cout << lcs(X, Y) << endl;
  }
}
