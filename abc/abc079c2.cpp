#include <iostream>

using namespace std;

int main() {
  string s;
  char op[4];
  cin >> s;
  int a,b,c,d;
  // cout << "s:" << s << endl;
  for (int bit = 0; bit < (1<<3); bit++) {
    // cout << bitset<4>(bit) << endl;
    int sum = s[0] - '0';
    for (int i = 0; i < 3; i++) {
      if (bit & (1<<i)) {
        // cout << i << ":on" << endl;
        sum += (s[i+1] - '0');
        op[i] = '+';
      } else {
        // cout << i << ":off" << endl;
        sum -= (s[i+1] - '0');
        op[i] = '-';
      }
      // cout << "i:" << i << "," << s[i+1] << ", sum:" << sum << endl;
    }
    if (sum == 7) {
      cout << s[0] << op[0] << s[1] << op[1] << s[2] << op[2] << s[3] << << "=7" << endl;
      return 0;
    }
  }
}
