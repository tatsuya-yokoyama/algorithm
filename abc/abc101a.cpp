#include <iostream>

using namespace std;

int main() {
  int num = 0;
  string s;
  cin >> s;
  for (int i = 0; i < 4; i++) {
    if (s[i] == '+') {
      num++;
    } else {
      num--;
    }
  }
  cout << num << endl;
}
