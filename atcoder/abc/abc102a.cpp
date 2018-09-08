#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = n; i <= 2 * n; i++) {
    if (i % 2 != 0) {
      continue;
    } else {
      if (i % n == 0) {
        cout << i << endl;
        return 0;
      }
    }
  }
}
