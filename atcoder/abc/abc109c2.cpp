#include <iostream>

using namespace std;

int gcd(int x, int y) {
  return y ? gcd(y, x % y) : x;
}

int main() {
  int N, X;
  cin >> N >> X;
  int D[100100];
  cout << endl;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    D[i] = abs(X-num);
  }
  int ans = D[0];
  for (int i = 1; i < N; i++) {
    ans = gcd(ans, D[i]);
  }
  cout << ans << endl;
}
