#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  long long x;
  vector <long long> v;

  cin >> N >> x;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());

  // cout << "---------" << endl;
  int rest = x;
  int num = 0;
  for (auto it = v.begin(); it != v.end(); it++){
    // cout << "rest:" << rest << "a_i:" << *it << endl;
    if (rest >= *it) {
      rest -= *it;
      num++;
    }
    // cout << *it << endl;
  }
  // あまったら一人犠牲になってもらう
  // cout << "num:" << num << "x:" << x << endl;
  if (rest > 0 && num == N) {
    // cout << "heru" << endl;
    num--;
  }
  cout << num << endl;
}
