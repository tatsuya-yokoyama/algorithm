#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, q;
  int S[100010];
  int T[50010];

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> T[i];
  }
  int count = 0;
  for (int i = 0; i < q; i++) {
    if (*lower_bound(S, S+n, T[i]) == T[i]) {
      count++;
    }
  }
  cout << count << endl;
}
