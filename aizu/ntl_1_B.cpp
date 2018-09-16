#include <iostream>
#define M 1000000007
using namespace std;

unsigned long long power(unsigned long long x, unsigned long long n) {
  if (n == 0) {
    return 1;
  }
  unsigned long long res = power(x, n/2);
  if (n % 2 == 0) {
    return res * res % M;
  } else {
    return res * res % M * x % M ;
  }
}

int main() {
  unsigned long long m, n;
  cin >> m >> n;
  cout << power(m, n) << endl;
}
