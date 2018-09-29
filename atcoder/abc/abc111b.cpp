#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int a[100];
  a[0] = 111;
  a[1] = 222;
  a[2] = 333;
  a[3] = 444;
  a[4] = 555;
  a[5] = 666;
  a[6] = 777;
  a[7] = 888;
  a[8] = 999;
  for (int i = 0; i < 9; i++) {
    if (a[i] >= N) {
      cout << a[i] << endl;
      return 0;
    }
  }
}
