#include <iostream>

using namespace std;

int D, G;
int p[11];
int c[11];

int main() {
  // 入力
  cin >> D >> G;
  for (int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
  }

  int min_num = 100 * 10;
  // 全部解くor全く解かないで全探索
  for (int bit = 0; bit < (1<<D); bit++) {
    int S = 0;
    int num = 0;
    // cout << bitset<10>(bit) << endl;
    for (int i = 0; i < D; i++) {
      if (bit & (1<<i)) {
        S += p[i] * 100 * (i+1) + c[i];
        num += p[i];
      }
    }
    if (S >= G) {
      if (num < min_num) {
        min_num = num;
        // cout << bitset<10>(bit) << ", " << num << ", " << min_num << ", " << S << endl;
      }
    } else {
      for (int i = D; i >= 0; i--) {
        if ( !(bit & (1<<i)) ) {
          for (int j = 0; j < p[i]; j++) {
            S += 100 * (i+1);
            num += 1;
            if (S >= G) {
              if (num < min_num) {
                min_num = num;
                // cout << bitset<10>(bit) << ", " << num << ", " << min_num << ", " << S << endl;
              }
            }
          }
        }
      }
    }
  }
  cout << min_num << endl;
}
