#include <iostream>
#include <complex>

using namespace std;

bool isPrime(int n) {
  if (n == 2) {
    return true;
  }
  // cout << "sqrt:" << sqrt(n) << endl;
  for (int i = 2; i <= sqrt(n); i++) {
    // cout << "n:" << n << ", i:" << i << endl;
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (isPrime(num)) {
      // cout << "num:" << num << ", prime" << endl;
      count++;
    }
  }
  cout << count << endl;
}
