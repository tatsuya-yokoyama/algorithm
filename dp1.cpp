#include <iostream>

using namespace std;

int main() {
  int n;
  int a[10010];
  int d[10010];

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  d[0] = 0;
  for (int i = 0; i < n; i++) {
    //cout << i << "," << a[i-1] << endl;
    //int max_d = d[i-1];
    d[i+1] = max(d[i], d[i] + a[i]);
  }
  cout << d[n] << endl;
}
