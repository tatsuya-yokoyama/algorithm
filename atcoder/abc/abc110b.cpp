#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N);
  vector<int> y(M);
  int x_max = X;
  int y_min = Y;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    x_max = max(x_max, x[i]);
  }
  for (int i = 0; i < M; i++) {
    cin >> y[i];
    y_min = min(y_min, y[i]);
  }
  if (x_max < y_min) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
}
