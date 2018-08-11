#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  // 4ドルケーキ
  for (int i = 0; i < 30; i++) {
    // 7ドルケーキ
    for (int j = 0; j < 15; j++) {
      int sum = 4 * i + 7 * j;
      if (sum == n) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
