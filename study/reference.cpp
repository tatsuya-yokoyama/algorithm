#include <iostream>

using namespace std;

void twice(int& a) {
  cout << a << endl;
  a *= 2;
  cout << a << endl;
}


int main() {
  int v = 16;
  cout << v << endl;
  twice(v);
  cout << v << endl;
}
