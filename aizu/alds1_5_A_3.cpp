#include <iostream>

using namespace std;

int n, a[2010];
int dp[21][2010];

// i番目以降の要素を使って、mを作れれば1、作れなければ0
int solve(int i, int m) {
  if (dp[i][m] == 2 or dp[i][m] == 1) {
    //cout << "cached" << endl;
    return dp[i][m];
  } else {
    //cout << "not cached" << endl;
  }
  //cout << i << "," << m << endl;
  if (m == 0) {
    dp[i][m] = 2;
    return 2;
  }
  if (i >= n) {
    dp[i][m] = 1;
    return 1;
  }
  if (solve(i+1, m) == 2 || solve(i+1, m-a[i]) == 2) {
    dp[i][m] = 2;
    return 2;
  } else {
    dp[i][m] = 1;
    return 1;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int m ;
    cin >> m;
    if (solve(0, m) == 2) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
