#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, X, min_ans;
  vector<int> v;
  cin >> N >> X;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  // cout << "------" << endl;
  int prev_i = -1;
  int next_i = -1;

  if (v.size() >= 2) {
    // 各都市間の最小の距離min_diffを求める
    int min_diff = v[v.size() - 1];
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i+1] - v[i] < min_diff) {
        min_diff = v[i+1] - v[i];
      }
    }

    int nearest_diff;
    // Xの最近隣都市との最短距離nearest_diffを求める
    if (X < v[0]) {
      // cout << "p1" << endl;
      nearest_diff = v[0] - X;
    } else if (X == v[0]) {
      nearest_diff = v[1] - X;
    } else if (X == v[v.size() - 1]) {
      nearest_diff = X - v[v.size() - 2];
    } else if (X > v[v.size() - 1]) {
      // cout << "p2" << endl;
      nearest_diff = v[v.size() - 1] - X;
    } else {
      // cout << "p3" << endl;
      for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] == X) {
          prev_i = i - 1;
          next_i = i + 1;
          nearest_diff = min(X - v[prev_i], v[next_i] - X);
          break;
        }
        if (v[i] < X && X < v[i+1]) {
          prev_i = i;
          next_i = i+1;
          int prev_diff = X - v[prev_i];
          int next_diff = v[next_i] - X;

          nearest_diff = min(X - v[prev_i], v[next_i] - X);
          if (prev_diff % nearest_diff == 0 && next_diff % nearest_diff == 0) {
            break;
          } else {
            for (int j = nearest_diff; j >= 1; j--) {
              if (prev_diff % j == 0 && next_diff % j == 0) {
                nearest_diff = j;
                break;
              }
            }
          }
          break;
        }
      }
    }

    // min_diffとnearest_diffでより小さい方が答え
    int ans = min(nearest_diff, min_diff);

    if (nearest_diff % ans == 0 && min_diff % ans == 0) {
      cout << ans << endl;
      return 0;
    } else {
      for (int i = ans; i >= 1; i--) {
        if (nearest_diff % i == 0 && min_diff % i == 0) {
          int next_flg = false;
          for (int i = 0; i < v.size() - 1; i++) {
            if ((v[i+1] - v[i]) % i != 0) {
              next_flg = true;
              break;
            }
          }
          if (next_flg) {
            continue;
          } else {
            cout << i << endl;
            return 0;
          }
        }
      }
    }
  } else {
    // 都市が1つしかない場合は、初期値Xとその都市との距離が答え
    cout << abs(X-v[0]) << endl;
  }
}
