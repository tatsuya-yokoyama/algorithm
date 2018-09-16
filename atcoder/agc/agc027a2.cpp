#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <numeric> // accumulate

using namespace std;

int main() {
  int N;
  int x;
  vector <int> v;

  cin >> N >> x;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  int rest = x;
  int count = 0;

  for (auto it = v.begin(); it != v.end(); it++){
    if (rest < *it) break;
    rest -= *it;
    count++;
  }
  // お菓子があまってて全員にくばっちゃってたら一人押し付けて犠牲になってもらう
  // 全員にくばってなければ、残りの人に押し付ければよいので特にインクリメントしない
  if (rest > 0 && count == N) {
    count = N - 1;
  }
  cout << count << endl;
}
