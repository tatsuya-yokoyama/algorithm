#include <iostream>

using namespace std;

int top, S[100];

void push(int x) {
  S[++top] = x;
}

int pop() {
  return S[top--];
}

int main() {
  string s;
  while(cin >> s) {
    if (s == "+") {
      int s1 = pop();
      int s2 = pop();
      push(s1+s2);
    } else if (s == "-") {
      int s1 = pop();
      int s2 = pop();
      push(s1-s2);
    } else if (s == "*") {
      int s1 = pop();
      int s2 = pop();
      push(s1*s2);
    } else {
      push(stoi(s));
    }
  }
  cout << pop() << endl;
}
