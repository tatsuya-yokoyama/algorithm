#include <iostream>
#include<stack>

using namespace std;

int main() {
  stack<int> S;
  S.push(325);
  S.push(1212);
  S.push(92);
  S.push(10);
  cout << S.size() << endl;
  cout << S.top() << endl;
  S.pop();
  cout << S.top() << endl;
}
