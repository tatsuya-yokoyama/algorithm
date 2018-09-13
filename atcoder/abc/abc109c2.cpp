#include <iostream>

using namespace std;

int gcd(int a, int b) {
  int less, greater;
  if (a < b) {
    less = a;
    greater = b;
  } else {
    less = b;
    greater = a;
  }
  int remainder = greater % less;
  if (remainder == 0) {
    return less;
  } else {
    return gcd(less, remainder);
  }
}

int main() {
  int N, X;
  cin >> N >> X;
  int D[100100];
  cout << endl;
  // cout << "-------" << endl;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    D[i] = abs(X-num);
    // cout << D[i] << endl;
  }
  // cout << "-------" << endl;
  int ans = D[0];
  for (int i = 1; i < N; i++) {
    // cout << "D[i] " << D[i] << " D[i+1] " << D[i+1] << endl;
    ans = gcd(ans, D[i]);
  }
  cout << ans << endl;
}
