#include <iostream>

using namespace std;

int main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int max = 0;
  int sum = 0;
  for (int i = 0; i <= 2; i++) {
    //cout << a[i] << endl;
    if (a[i] > max) {
      max = a[i];
    }
    sum += a[i];
  }

  int goal = max * 3;
  int diff = goal  - sum;
  //cout << "sum:" << sum << endl;
  //cout << "max:" << max << endl;
  //cout << "goal:" << goal << endl;
  int times = diff / 2;
  if (goal % 2 != sum % 2) {
    times += 2;
  }
  cout << times << endl;
}
