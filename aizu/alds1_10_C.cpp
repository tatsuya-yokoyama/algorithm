#include <iostream>

using namespace std;

int lcs(string X, string Y) {
  int memo[1010][1010];
  int maxl = 0;

  // 初期化、境界条件を考慮して場合分け
  // for (int i = 0; i < X.size(); i++) {
  //   if (X[i] == Y[0]) {
  //     memo[i][0] = 1;
  //   } else {
  //     memo[i][0] = 0;
  //   }
  //   maxl = max(maxl, memo[i][0]);
  // }
  //
  // for (int j = 0; j < Y.size(); j++) {
  //   if (X[0] == Y[j]) {
  //     memo[0][j] = 1;
  //   } else {
  //     memo[0][j] = 0;
  //   }
  //   maxl = max(maxl, memo[0][j]);
  // }

  // cout << memo[0][0] << endl;
  // cout << "--------------" << endl;

  for (int i = 0; i < X.size(); i++) {
    for (int j = 0; j < Y.size(); j++) {
      if (i == 0 && j == 0) {
        if (X[i] == Y[j]) {
          memo[i][j] = 1;
        } else {
          memo[i][j] = 0;
        }
      }
      if (i == 0) {
        if (X[i] == Y[j]) {
          memo[i][j] = max(memo[i][j-1]);
        } else {
          memo[i][j] = 0;
        }
      } else {
        if (X[i] == Y[j]) {
          memo[i][j] = memo[i-1][j-1] + 1;
        } else {
          memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
        }
      }
      maxl = max(maxl, memo[i][j]);
      //cout << i << "," << j << "," << X[i] << "," << Y[j] << "," << maxl << endl;
    }
  }
  return maxl;
}

int main() {
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    string X, Y; cin >> X >> Y;
    //cout << endl;
    cout << lcs(X, Y) << endl;
  }
}
