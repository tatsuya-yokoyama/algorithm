#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  long long ans = 0;
  long long d = 0;
  for (int i = 1; i <= N; i++) {
    if (K % 2 == 0) {
      if (i % K == 0) ans++;
      else if (i % (K/2) == 0) d++;
    } else {
      if (i % K == 0) ans++;
    }
  }
  cout << ans * ans * ans + d * d * d << endl;
}
