#include <iostream>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int count = 0;
  int l = max({a,c});
  int r = min({b,d});
  //cout << l << "," << r << endl;
  int dis = max(r - l, 0);
  cout << dis << endl;
}
