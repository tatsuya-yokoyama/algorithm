#include <iostream>

using namespace std;

int main() {
  int a[30];
  int n, K;
  cin >> n >> K;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int bit = 0; bit < (1<<n); bit++) {
    cout << bitset<4>(bit) << endl;
    for (int i = 0; i < n; i++) {
      if (bit & (1<<i)) {
        cout << i << ":on" << endl;
      } else {
        cout << i << ":off" << endl;
      }
    }
  }
}
