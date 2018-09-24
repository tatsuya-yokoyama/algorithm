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
  int num = 2;

  vector<int> v(num);
  v[4] = 23;
  cout << v[4] << endl;


  // for (int i = 0; i < num+1; i++) {
  //   int x;
  //   cin >> v[i];
  //   cin >> v[231];
  //   // v.push_back(x);
  // }
  // cout << v[231] << endl;
  return 0;
  print(v);

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    (*it)++;
  }
  print(v);
}
