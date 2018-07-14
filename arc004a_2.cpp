#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N;
  int x[101];
  int y[101];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }
  float d_max = 0.0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      int dx = abs(x[i] - x[j]);
      int dy = abs(y[i] - y[j]);
      float d = sqrt(dx*dx + dy*dy);
      if (d > d_max) {
        d_max = d;
      }
    }
  }
  cout << d_max << endl;
}
