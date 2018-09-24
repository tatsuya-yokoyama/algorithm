#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M, X, Y;
  vector<int> x;
  vector<int> y;

  cin >> N >> M >> X >> Y;

  int num;
  for (int i = 0; i < N; i++) {
    cin >> num;
    x.push_back(num);
  }
  sort(x.begin(), x.end(), std::greater<int>());
  for (int i = 0; i < M; i++) {
    cin >> num;
    y.push_back(num);
  }
  sort(y.begin(), y.end());

  int x_max = x[0];
  int y_min = y[0];
  // cout << "x_max:" << x_max << endl;
  // cout << "y_min:" << y_min << endl;

  // cout << x_max << " < Z <= " << y_min << endl;

  for (int i = X+1; i <= Y; i++) {
    if (i > x_max && i <= y_min) {
      // cout << i << endl;
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
}
