#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  for (int x = 111; x <= 999; x += 111) {
    if (x >= N) {
      cout << x << endl;
      return 0;
    }
  }
}
