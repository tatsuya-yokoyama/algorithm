#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it;
  }
  cout << endl;
}

int main() {
  vector<int> v;
  for (int i = 0; i < 4; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  print(v);

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    (*it)++;
  }
  print(v);
}
