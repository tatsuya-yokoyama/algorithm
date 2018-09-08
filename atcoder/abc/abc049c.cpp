#include <iostream>

using namespace std;

string devide[4] = {"dream", "dreamer", "erase", "eraser"};

string cut_word(string base_word);

int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    //cout << S << endl;
    for (int i = 0; i < 4; i++) {
        reverse(devide[i].begin(), devide[i].end());
    }
    // 単語で切り取る
    while(1) {
      //cout << "1 times" << endl;
      string before_S = S;
      S = cut_word(S);
      //cout << "-------------------" << endl;
      //cout << before_S.size() << endl;
      //cout << S.size() << endl;
      if (before_S.size() == S.size()) {
        //cout << "same=============" << endl;
        break;
      }

    }

    if (S.size() == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
}

string cut_word(string base_word) {
  for (int i = 0; i < 4; i++) {
    bool is_ok = true;
    for (int j = 0; j < devide[i].size(); j++) {
      if (base_word[j] != devide[i][j]) {
        is_ok = false;
      }
    }
    //cout << "-------------------" << endl;
    //cout << devide[i] << endl;
    // 実際に切り取る
    if (is_ok) {
      for (int j = 0; j < devide[i].size(); j++) {
        base_word.erase(base_word.begin());
      }
      //cout << "OK" << endl;
    } else {
      //cout << "NG" << endl;
    }
  }
  return base_word;
}
