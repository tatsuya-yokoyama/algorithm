#include <iostream>
#include <stack>
using namespace std;

int main() {
  bool flag = true;

  string str;
  //cout << "--------------" << endl;
  int i = 0;

  while(getline(cin, str)) {
    bool already_cout = false;
    // cout << str << "===============" << endl;
    //cout << i << endl;
    if (str == ".") {
      // cout << "brak" << endl;
      break;
    }
    stack<char> S;
    bool total_ok = true;
    for (int i = 0; i < str.size(); i ++) {
      if (str[i] == '(' || str[i] == '[' || str[i] == ')' || str[i] == ']') {
        // cout << i << "," << str[i] <<endl;
      }

      // 左括弧
      if (str[i] == '(' || str[i] == '[') {
        S.push(str[i]);
      }
      // 右括弧
      else if (str[i] == ')') {
        bool is_ok = true;
        if (S.empty()) {
          is_ok = false;
          total_ok = false;
        } else {
          if (S.top() == '(') {

            S.pop();
          } else {
            is_ok = false;
            total_ok = false;
            already_cout = true;
            // cout << "kokode no, " << S.top() << "," << i << endl;
            cout << "no" << endl;
            break;
          }
        }
      }
      else if (str[i] == ']') {
        bool is_ok = false;

        if (S.empty()) {
          if (i >= 99) {
            // cout << "koko kitayo 1" << endl;
          }
          is_ok = false;
          total_ok = false;
        } else {
          if (S.top() == '[') {
            if (i >= 99) {
              // cout << "koko kitayo 2" << "," << i << endl;
            }
            S.pop();
          } else {
            if (i >= 99) {
              // cout << "koko kitayo 3" <<  "," << i << endl;
            }
            is_ok = false;
            total_ok = false;
            already_cout = true;
            // cout << "kokode no 2" << endl;
            cout << "no" << endl;
            break;
          }
        }
      }
    }
    if (!S.empty()) {
      // cout << "dame" << endl;
      total_ok = false;
    }
    if (total_ok) {
      cout << "yes" << endl;
    } else if (!already_cout) {
      cout << "no" << endl;
    }
  }
}
