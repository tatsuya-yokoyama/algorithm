#include<iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int total_count = 0;
  for (int i = 1; i <= n; i++) {
    int count = 0;
    if (i % 2 == 0) {
      continue;
    }
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        count++;
      }
    }
    if (count == 8) {
      // cout << i << "[8]" << count << endl;
      total_count++;
    } else {
      // cout << i << "[not 8]" << count << endl;
    }
  }
  cout << total_count << endl;
}
