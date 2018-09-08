#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;
  bool ok1 = false;
  // 1
  if (S[0] == 'A') {
    ok1 = true;
  }
  // 2
  bool ok2 = false;
  int ok2_index = 0;
  for (int i = 2; i <= S.length() - 2; i++) {
    // まだ一度もCが出てきてない時だけ受け入れることに注意
    if (!ok2 && S[i] == 'C') {
      ok2 = true;
      ok2_index = i;
    }
  }
  //3
  bool ok3 = true;
  for (int i = 1; i < S.length(); i++) {
    // 2でCがでてきたものはスキップする
    if (i == ok2_index) {
      continue;
    }
    else {
      // ひつでも大文字が来たらNG
      if (isupper(S[i])) {
        ok3 = false;
        break;
      }
    }
  }
  if (ok1 && ok2 && ok3) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
}
