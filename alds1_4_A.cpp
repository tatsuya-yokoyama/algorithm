#include <iostream>
#include <vector>

using namespace std;

int n, q;
int S[10010];
int T[510];
// vector<int> C;

// int search(int x) {
//   int ret = -1;
//   for (int i = 0; i < q; i++) {
//     if (T[i] == x) {
//       ret = i;
//       break;
//     }
//   }
//   return ret;
// }
//
// int linearSearch(int x) {
//   // 比較
//   // 1. 終わったかどうか
//   // 2. keyと同じかどうか
//   for (int i = 0; i < n; i++) {
//     if (A[i] == x) {
//       return i;
//     }
//   }
//   return -1;
// }

int linearSearch(int x) {
  int i = 0;
  S[n] = x;
  // 1. keyと同じかどうか
  while(S[i] != x) {
    i++;
  }
  // cout << x << ", i:" << i << ", n:" << n << endl;
  if (i >= n) {
    return -1;
  } else {
    return i;
  }
}

//
// int searchC(int x) {
//   int ret = -1;
//   for (auto itr = C.begin(); itr != C.end(); itr++) {
//     if (*itr == x) {
//       ret =
//       return ret;
//     }
//   }
// }

int main() {
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
    int ret = linearSearch(T[i]);
    if (ret != -1) {
      count++;
    }
  }
  cout << count << endl;
}
