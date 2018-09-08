#include <iostream>

using namespace std;

int main() {
  char capital = 'B';
  char small = 'b';
  char hoge = capital;
  if (small >= 'A' && small <= 'Z') {
    cout << "capital!" << endl;
  } else {
    cout << "small" << endl;
  }
}
