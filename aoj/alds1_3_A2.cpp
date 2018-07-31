#include <iostream>
#include<stack>

using namespace std;

int main() {
  stack <int> S;
  string s;
  while(cin >> s) {
    if (s == "+") {
      int s1 = S.top();
      S.pop();
      int s2 = S.top();
      S.pop();
      // cout << "push+!:" << "s1:" << s1 << " s2:" << s2 << ", ans:" << s1+s2 << endl;
      S.push(s1+s2);
    } else if (s == "-") {
      int s1 = S.top();
      S.pop();
      int s2 = S.top();
      S.pop();
      //cout << "push-!:" << "s1:" << s1 << " s2:" << s2 << ", ans:" << s1-s2 << endl;
      S.push(s2-s1);
    } else if (s == "*") {
      int s1 = S.top();
      S.pop();
      int s2 = S.top();
      S.pop();
      // cout << "push*!:" << "s1:" << s1 << " s2:" << s2 << ", ans:" << s1*s2 << endl;
      S.push(s1*s2);
    } else {
      // cout << "push!:" << s << endl;
      S.push(stoi(s));
    }
  }
  cout << S.top() << endl;
}
