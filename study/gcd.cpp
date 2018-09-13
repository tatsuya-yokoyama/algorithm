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
  int a, b;
  cin >> a >> b;
  cout << "gcd of " << a << " and " << b << " is " << gcd(a,b) << endl;
}
