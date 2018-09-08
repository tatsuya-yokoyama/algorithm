#include<iostream>
using namespace std;

int main() {
  int n, i, b[32];
  cin >> n;
  for (i = 0; n > 0; i++) {
    b[i] = n % 2;
    n = n / 2;
    // cout << "i:" << i << ", " << (1<<i) << ":" << b[i] << ", n:" << n << endl;
  }
  while(i > 0) {
    i--;
    cout << b[i];
  }
  cout << endl;
}
