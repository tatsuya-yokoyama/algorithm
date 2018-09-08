#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  int dx, dy;
  dx = x2 - x1;
  dy = y2 - y1;

  // cout << "dx:" << dx << ", dy:" << dy << endl;

  x3 = x2 - dy;
  y3 = y2 + dx;

  x4 = x3 - dx;
  y4 = y3 - dy;

  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
