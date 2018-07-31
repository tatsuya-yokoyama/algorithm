#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;x
  int A1[110];
  int A2[110];

  for (int i = 0; i < N; i++) {
    cin >> A1[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> A2[i];
  }
  int max = 0;
  for (int k = 0; k < N; k++) {
    int count = 0;
    for (int l = 0; l <= k; l++) {
      count += A1[l];
    }
    for (int l = k; l < N; l++) {
      count += A2[l];
    }

    if (count > max) {
      max = count;
    }
  }
  cout << max << endl;
}
