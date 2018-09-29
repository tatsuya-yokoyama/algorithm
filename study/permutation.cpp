#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // int a[] = {1,2,3,9};
  // do {
  //   for (int i = 0; i < 4; i++) {
  //     cout << a[i];
  //   }
  //   cout << endl;
  // } while(next_permutation(a, a+4));

  // vector<int> b;
  // b.push_back(1);
  // b.push_back(2);
  // b.push_back(3);
  // b.push_back(4);
  // do {
  //   for (int x : b) {
  //     cout << x;
  //   }
  //   cout << endl;
  // } while(next_permutation(b.begin(), b.end()));
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  do {
    for (int x : v) {
      cout << x;
    }
    cout << endl;
  } while(next_permutation(v.begin(), v.end()));

}
