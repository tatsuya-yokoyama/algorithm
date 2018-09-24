#include <iostream>

using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  long long x[200010];
  // i番目のゴミのインデックスと配列のインデックスをあわせる
  x[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> x[i];
  }

  // 累積和を作っておく
  long long s[200010]; // i=1からi=インデックス番目までの距離の和
  s[0] = 0;
  for (int i = 1; i <= N; i++) {
    s[i] += s[i-1] + x[i];
    cout << "i:" << s[i] << endl;
  }

  // 必要なエネルギーの最小値
  long long e_min;

  // k回ゴミを捨てる場合のエネルギーを計算
  // ゴミはN個なので、kはNまででよい
  for (int k = 1; k <= N; k++) {
    long long e = 0;

    // 各ごみ収集で、1番目に拾うゴミ * k回のごみ収集
    // k回を加算
    for (int i = 0; i < k; i++) {
      e += 5 * x[N-i];
      // cout << "k:" << k << ", i:" << i << ", e:" << e << endl;
    }
    // ここまでOK
    
    // cout << "------------------" << endl;
    int weight = 5;
    int count = 0;
    // さっきk回捨ててるから、N-kから始まる
    for (int i = N-k; i >= 0; i--) {
      e += weight * x[i];
      // cout << "i:" << i << ", e:" << e << ", weight:" << weight << ", x[i]:" << x[i] <<endl;
      count++;
      if (count >= k) {
        count = 0;
        weight += 2;
      }
    }
    e += k * X + N * X;
    // cout << "k:" << k << ", e:" << e << ", add:" << k * X + N + X << endl;
    // cout << "k:" << k << ", e:" << e << endl;
    if (k == 1) {
      e_min = e;
    } else {
      e_min = min(e_min, e);
    }
    // cout << "==============" << endl;
  }
  cout << e_min << endl;
}
