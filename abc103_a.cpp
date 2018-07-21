#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a;
  int val;
  cin >> val;
  a.push_back(val);
  cin >> val;
  a.push_back(val);
  cin >> val;
  a.push_back(val);
  sort(a.begin(), a.end());
  //cout << a[0] << endl;
  //cout << a[1] << endl;
  //cout << a[2] << endl;
  int cost = 0;
  cost += abs(a[1] - a[0]);
  cost += abs(a[2] - a[1]);
  cout << cost << endl;
}
