#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, bool> T;

  for (int i = 0; i < n; i++) {
    string command;
    string str;
    cin >> command >> str;
    if (command == "insert") {
      T[str] = true;
    } else if (command == "find") {
      if (T[str]) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
}
