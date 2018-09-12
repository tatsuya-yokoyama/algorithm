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
  if (v.size() >= 2) {
    for (int i = 1; i < 10000000; i++) {
      for (j = 1; j < v.size() - 1; j++) {
        if ()
      }
    }
  }
}
