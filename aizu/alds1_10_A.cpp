#include <iostream>

using namespace std;

long long F[50];

long long fib(int n) {
  // すでに計算済み
  if (F[n] != -1) {
    return F[n];
  }
  if (n == 0 || n == 1) {
    return F[n] = 1;
  } else {
    return F[n] = fib(n-1) + fib(n-2);
  }
}

int main() {
  int n;
  cin >> n;
  F[0] = F[1] = 1;
  for (int i = 2; i <= n; i++) {
      F[i] = F[i-2] + F[i-1];
  }
  cout << F[n] << endl;

  // // 初期化
  // for (int i = 0; i < 50; i++) {
  //   F[i] = -1;
  // }
  // cout << fib(n) << endl;
}
