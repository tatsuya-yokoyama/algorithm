#include <iostream>

using namespace std;

int D, G;
int p[11];
int c[11];
int dp[1000][100];

int getMinNum(int i, int g) {
  if (i == 0) {
    return - 1;
  }
  int min_num1 = getMinNum(i+1, g);
  int min_num2;
  for (int j = 0; j < p[i]; j++) {
    int sum = 100 * (1 + j);
    min2 = min(min2, getMinNum(i+1, g-sum) + j + 1);
  }
  min2 = min(min2, getMinNum(i+1, g-sum-c[i]) + p[i]);
  return min2;
}

int main() {
  // 入力
  cin >> D >> G;
  for (int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
  }
  // 与えられたpiすべてを使っての、最小問題数を求める
  int min_num = getMinNum(0, G);
  cout << min_num << endl;

}
