#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  long long total = 0;
  // 文字の間に+が入る全パターンをbitを使って列挙
  // cout << "-------------" << endl;
  for (int bit = 0; bit < (1<<(n-1)); bit++) {
    // +の場合を挿入していく
    // とりあえず文字列で
    string t;
    for (int i = 0; i < n; i++) {
      t += s[i];
      if (bit & (1<<i)) {
        t += "+";
      }
    }
    // cout << t << "=?" << endl;

    // あとは足し算してくだけ
    long long sum = 0;
    long long tmp = 0;
    for (int i = 0; i < t.size(); i++) {
      // cout << t[i] << endl;
      if (t[i] == '+') {
        sum += tmp;
        tmp = 0;
      } else {
        tmp = tmp * 10 + (t[i] - '0');
      }
    }
    sum += tmp;
    total += sum;
  }
  cout << total << endl;
}
