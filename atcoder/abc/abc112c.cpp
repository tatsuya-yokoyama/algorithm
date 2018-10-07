#include <iostream>

using namespace std;

int N;
int h[110];
int x[110];
int y[110];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
  }

  for (int pos_y = 0; pos_y <= 100; pos_y++) {
    for (int pos_x = 0; pos_x <= 100; pos_x++) {
      // 0以上: 暫定のH
      // -1: まだわからない時
      // -2: だめだとわかった時
      int H_tmp = -1;
      for (int i = 0; i < N; i++) {
        if (h[i] > 0) {
          int H_cal = h[i] + abs(y[i] - pos_y) + abs(x[i] - pos_x);
          if (H_tmp == -1) {
            H_tmp = H_cal;
          } else {
            if (H_cal != H_tmp) {
              H_tmp = -2;
              break;
            }
          }
        }
      }
      // だめだったら次の場所を探す
      if (H_tmp == -2) {
        continue;
      }
      for (int i = 0; i < N; i++) {
        // 高さ0の場合に矛盾していないか調べる
        if (h[i] == 0) {
          int d = abs(y[i] - pos_y) + abs(x[i] - pos_x);
          if (H_tmp > d) {
            H_tmp = -2;
            break;
          }
        }
      }
      if (H_tmp == -2) {
        continue;
      }
      cout << pos_x << " " << pos_y << " " << H_tmp << endl;
      return 0;
    }
  }
}
