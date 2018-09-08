#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;
  int a, b, c, d;
  a = S[0] - '0';
  b = S[1] - '0';
  c = S[2] - '0';
  d = S[3] - '0';
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        int sum = a;
        char opt1 = '+';
        char opt2 = '+';
        char opt3 = '+';
        if (i == 1) {
          sum += b;
        } else {
          opt1 = '-';
          sum -= b;
        }

        if (j == 1) {
          sum += c;
        } else {
          opt2 = '-';
          sum -= c;
        }
        if (k == 1) {
          sum += d;
        } else {
          opt3 = '-';
          sum -= d;
        }
        //cout << sum << endl;
        if (sum == 7) {
          char shiki = S[0];
          cout << a << opt1 << b << opt2 << c << opt3 << d << "=7"<< endl;
          return 0;
        }
      }
    }
  }
}
