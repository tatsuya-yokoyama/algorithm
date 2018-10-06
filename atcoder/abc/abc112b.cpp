#include <iostream>

using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  int MAX = 1 << 20;
  int min_cost = MAX;
  for (int i = 0; i < N; i++) {
    int c, t;
    cin >> c >> t;
    if (t <= T) {
      min_cost = min(c, min_cost);
    }
  }
  if (min_cost < MAX) {
    cout << min_cost << endl;
  } else {
    cout << "TLE" << endl;
  }
}
