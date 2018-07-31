#include <iostream>

using namespace std;

int n, U;
int w[110];
int v[110];

// i番目以降で重さの総和u以下となるように品物を選んだときのv
int search(int i, int u) {
  // iの上限はn-1。i>=nでは品物は選べない。
  if (i >= n) {
    return 0;
  }
  // これ以上入らない
  if (u - w[i] < 0) {
    return search(i+1, u);
  }
  return max(search(i+1, u), search(i+1, u-w[i]) + v[i]);
}

int main() {
  cin >> n >> U;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  int max_v = search(0, U);
  cout << max_v << endl;
}
