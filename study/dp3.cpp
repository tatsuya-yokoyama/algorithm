#include <iostream>

using namespace std;

int main() {
  int N, A;
  int a[110];
  bool dp[110][10010];

  cin >> N >> A;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  dp[0][0] = true;
  for (int i = 1; i < N; i++) {
    dp[0][i] = false;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= A; j++) {
      if (j == A) {
        //cout << "10---------" << endl;
      }
      if (j == 7) {
        //cout << "7---------" << endl;
      }
      if (i == 2 && j == 5) {
        cout <<"smdgief"<<endl;
      }
      char pattern = 'A';
      if(j >= a[i]) {
        pattern = 'A';
        if (i == 2 && j == 5) {
          cout << j - a[i] << endl;
          if (dp[i][j - a[i]]) {
            cout << "True" << endl;
          } else {
            cout << "False" << endl;
          }
        }
        dp[i+1][j] |= dp[i][j - a[i]];

      } else {
        pattern = 'B';
        dp[i+1][j] |= dp[i][j];
      }
      if (dp[i+1][j]) {
        cout << "[T]" << pattern << "," << i+1 << "," << j << endl;
      } else {
        cout << "[F]" << pattern << "," << i+1 << "," << j << endl;
      }
    }
  }
  if (dp[N][A]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
