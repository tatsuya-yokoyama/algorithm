#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0 ; i < n; i++) {
    int num;
    cin >> num;
    a.push_back(num);
  }
  sort(a.begin(), a.end(), greater<int>());

  int sum_a = 0;
  int sum_b = 0;
  for (int i = 0; i < n; i++) {
    int num = a.front();
    a.erase(a.begin());
    if (i % 2 == 0) {
      sum_a += num;
    } else {
      sum_b += num;
    }
  }
  cout << sum_a - sum_b << endl;
}
