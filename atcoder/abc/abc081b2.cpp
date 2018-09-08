#include <iostream>

using namespace std;

int main() {
  int n;
  int a[201];
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count = 0;
  bool is_even = true;
  while(is_even) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
          a[i] /= 2;
        } else {
          is_even = false;
          //cout << a[i] << endl;
          //cout << "break" << endl;
          break;
        }
    }
    if (is_even) {
      //cout << "count up----" << endl;
      count++;
    }
  }
  cout << count << endl;
}
