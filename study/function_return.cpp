#include<iostream>

using namespace std;

int hoge() {
  int a = 0;
  return a = 1432;
}

int main() {
  int foo = hoge();
  cout << foo << endl;
  cout << foo = 5432;
}
