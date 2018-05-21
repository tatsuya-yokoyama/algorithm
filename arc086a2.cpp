#include <iostream>

using namespace std;

int main() {
  int N;
  int t[100001], x[100001], y[100001];
  t[0] = x[0] = y[0] = 0;
  cin >> N;
  for (int i = 1; i <= N ; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }

  bool is_ok = true;
  //cout << "-------------" << endl;
  for (int i = 0; i <= N - 1; i++) {
    int z = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
    int t_diff = t[i+1] - t[i];
    if (t_diff < z) {
      is_ok = false;
    }
    // 偶数、奇数が一致する必要あり
    if (z % 2 != t_diff % 2) {
      is_ok = false;
    }
  }
  if (is_ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
