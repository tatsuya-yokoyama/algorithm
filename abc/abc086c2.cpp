#include <iostream>

using namespace std;

bool is_ok(int t_diff, int d);

int main() {
  int n;
  cin >> n;
  int t[100001];
  int x[100001];
  int y[100001];

  t[0] = x[0] = y[0] = 0;
  // 入力
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];

  }
  // 確認
  for (int i = 0; i <= n-1; i++) {
    int t_diff, x_diff, y_diff;
    t_diff = t[i+1] - t[i];
    x_diff = x[i+1] - x[i];
    y_diff = y[i+1] - y[i];
    int d = abs(x_diff) + abs(y_diff);
    //cout << i << "," << t[i+1] << "," << t[i] << "," << t_diff << "," << d << "----" << endl;
    if (!is_ok(t_diff, d)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

bool is_ok(int t_diff, int d) {
  if (d > t_diff) {
    return false;
  }
  if (d % 2 != t_diff % 2) {
    return false;
  }
  return true;
}
