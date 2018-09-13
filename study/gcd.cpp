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

int gcd2(int a, int b) {
  int less, greater;
  less = a;
  greater = b;
  int remainder = greater % less;
  if (remainder == 0) {
    return less;
  } else {
    return gcd2(less, remainder);
  }
}

int gcd3(int x, int y) {
  cout << "x:" << x << ", y:" << y << endl;
  return y ? gcd3(y, x % y) : x;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << endl;
  int gcd = gcd3(a,b);
  cout << "gcd of " << a << " and " << b << " is " << gcd << endl;
}
