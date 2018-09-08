#include <iostream>

using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;

  bool can_continue = true;
  int l = 0;
  // 10,000
  for (int i = 0; i <= N; i++) {
    if (!can_continue) {
      break;
    }
    // 5,000
    for (int j = 0; j <= N; j++) {
      l++;
      if (l % 1000000 == 0) {
        //cout << l << " times" <<endl;
      }
      if (!can_continue) {
        break;
      }
      int diff = N - i - j;
      int sum = 10000 * i + 5000 * j + 1000 * diff;
      //cout << i << " " << j << " " << diff << " " << sum << endl;
      if (diff >= 0 && 10000 * i + 5000 * j + 1000 * diff == Y) {
        cout << i << " " << j << " " << diff << endl;
        can_continue = false;
      }
    }
  }
  if (can_continue) {
    cout << "-1 -1 -1" << endl;
  }
}
