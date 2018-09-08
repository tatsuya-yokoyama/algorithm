#include <iostream>

using namespace std;

int main() {
  string s, t;
  bool can_match = false;
  cin >> s >> t;
  if (s == t) {
    can_match = true;
    cout << "Yes" << endl;
    return 0;
  }
  int m = s.size();
  // m回の回転を行う
  for (int i = 0; i < 102; i++) {

    // // 一回の回転
    char tmp = s[m - 1];
    for (int j = m - 2; j >= 0; j--) {
      s[j+1] = s[j];
    }
    s[0] = tmp;
    //cout << s << endl;
    if (s == t) {
      cout << "Yes" << endl;
      can_match = true;
      return 0;
    }
  }
  if (!can_match) {
    cout << "No" << endl;
  }
}
