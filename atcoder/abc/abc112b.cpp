#include <iostream>

using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  int min_cost = 100000;
  int min_cost_id = -1;
  for (int i = 0; i < N; i++) {
    int c, t;
    cin >> c >> t;
    if (t <= T) {
      // cout << c << "," << t << endl;
      if (c < min_cost) {
        min_cost = c;
        min_cost_id = i + 1;
      }
    }
  }
  if (min_cost_id == -1) {
    cout << "TLE" << endl;
  } else{
    cout << min_cost << endl;
  }
}
