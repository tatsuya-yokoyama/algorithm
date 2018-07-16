#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;
  int a[2010];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  int m[2010];
  for (int i = 0; i < q; i++) {
    cin >> m[i];
  }
  for (int l = 0; l < q; l++) {
    cout << "------------" << endl;
    cout << m[l] << endl;
    int sum = 0;
    bool can_make = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 1; j++) {
        if (j == 0) {
          sum += a[i];
        }
      }
    }
    if (sum == m[l]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
