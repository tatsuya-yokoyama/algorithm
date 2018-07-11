#include <iostream>

using namespace std;

string candidate_strings[4] = {"dream", "dreamer", "erase", "eraser"};
string cut_word(string base_word);


int main() {
  string S;
  cin >> S;
  // 入力された文字列を逆順にする
  reverse(S.begin(), S.end());

  // 候補の文字列も逆順にする
  for (int i = 0; i < 4; i++) {
    reverse(candidate_strings[i].begin(), candidate_strings[i].end());
  }
  while(1) {
    string before_S = S;
    S = cut_word(S);
    //cout << S.size() << endl;
    if (S.size() == 0) {
      //cout << "break success=============" << endl;
      cout << "YES" << endl;
      return 0;
    } else if (before_S.size() == S.size()) {
      break;
    }
  }
  cout << "NO" << endl;
}

string cut_word(string base_word) {
  // 各候補を一個ずつ見ていく

  //cout << "size" << candidate_strings.size() << endl;
  for (int i = 0; i < 4; i++) {
    bool is_ok = true;
    // 1文字ずつ見ていく
    for (int j = 0; j < candidate_strings[i].size(); j++) {
      // 文字が異なったらそこでNG
      if (base_word[j] != candidate_strings[i][j]) {
        is_ok = false;
      }
    }
    if (is_ok) {
      //cout << "cut by:" << candidate_strings[i] << endl;
      for (int j = 0; j < candidate_strings[i].size(); j++) {
        base_word.erase(base_word.begin());
        //cout << base_word << endl;
      }
    }
  }
  return base_word;
}
