#include <iostream>

using namespace std;

int main() {
  int K;
  cin >> K;
  int even_count = 0;
  int odd_count = 0;
  for (int i = 1; i <= K; i++) {
    if (i % 2 == 0) {
      even_count++;
    } else {
      odd_count++;
    }
  }
  int res = even_count * odd_count;
  cout << res << endl;
}
