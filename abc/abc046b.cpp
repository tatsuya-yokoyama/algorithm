#include <iostream>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int ans = K;
  for (int i = 1; i <= N-1; i++) {
    //cout << i << "times" << endl;
    ans *= (K-1);
  }
  cout << ans << endl;
}
