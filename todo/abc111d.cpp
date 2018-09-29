#include <iostream>

using namespace std;

int main() {
  int N;
  int x[1010];
  int y[1010];
  int d[1010];
  for (int i = 0; i < N; i ++) {
    cin >> x[i] >> y[i];
  }

  // 腕の個数を少しずつ増やしていく
  for (int m = 1; m < 10; m++) {
    // 腕がm本の時
    for (int i = 0; i < m; i++) {
      // 全部の腕に対して、色々な長さを試す
      for (int j = 0; j < 10; j++) {
        // 色々な長さをアサイン
        for (int l = 1; l < 10; l++) {
          d[j] = l;
        }
      }

    }

  }




}
