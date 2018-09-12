#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= 3; i++) {
    int num = a * b * i;
    if (num % 2 != 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
