#include <iostream>

using namespace std;

int main() {
  int n;
  int a[110];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int a_max = 0;
  int a_min = 1000000010;
  for (int i = 0; i < n; i++) {
    a_max = max(a_max, a[i]);
    a_min = min(a_min, a[i]);
  }
  cout << a_max - a_min << endl;
}
