#include<iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  //t r = n / k;
  //int g = n % k;
  // k > nのときでも誰かしらに配ることはできるのでこの条件でOK
  if (n % k == 0 ) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}
