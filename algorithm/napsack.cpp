#include <iostream>

using namespace std;

int search(int i, int u) {
  
}

int main() {
  int u = 5;
  int w[10];
  int v[10];
  int max_v = 0;

  w[0] = 2;
  v[0] = 3;

  w[1] = 1;
  v[1] = 2;

  w[2] = 3;
  v[2] = 4;

  w[3] = 2;
  v[3] = 2;

  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        for (int l = 0; l <= 1; l++) {
          cout << i << "," << j << "," << k << "," << l << endl;
          int sum_v = 0;
          int sum_w = 0;
          if (i == 1) {
            sum_v += v[0];
            sum_w += w[0];
          }
          if (j == 1) {
            sum_v += v[1];
            sum_w += w[1];
          }
          if (k == 1) {
            sum_v += v[2];
            sum_w += w[2];
          }
          if (l == 1) {
            sum_v += v[3];
            sum_w += w[3];
          }
          if (sum_w == u && sum_v > max_v) {
            max_v = sum_v;
          }
        }
      }
    }
  }
  cout << max_v << endl;
}
