#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, d;
  cin >> n;
  set<int> S;
  for (int i = 0; i < n; i++) {
    cin >> d;
    S.insert(d);
  }
  cout << S.size() << endl;
}
