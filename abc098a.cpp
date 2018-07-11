#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int min = N;

  // 各iでの、それより左側でWの人の数を数える
  int W[300010];
  W[0] = 0;
  if (S[1] == 'W') {
    W[0]++;
  }
  for (int i = 1; i < N; i++) {
    int w = 0;
    if (S[i] == 'W') {
      w = 1;
    }
    W[i] = W[i-1] + w;
    cout << i << "," << W[i] << endl;
  }
  cout << "--------------" << endl;
  // 各iでの、それより右側でEの人の数を数える
  int E[300010];
  E[N-1] = 0;
  for (int i = N-2; i >= 0; i--) {
    int e = 0;
    if (S[i] == 'E') {
      e = 1;
    }
    E[i] = E[i+1] + e;
    cout << i << "," << E[i] << endl;
  }

  return 0;
  for (int i = 0; i < N; i++) {
    int count = 0;
    // left
    for (int j = 0; j < i; j++) {
      if (S[j] == 'W') {
        count ++;
      }
    }
    //right
    for (int j = i + 1; j < N; j++) {
      if (S[j] == 'E') {
        count ++;
      }
    }
    //cout << i << "," << count << endl;
    if (count < min) {
      min = count;
    }
  }
  cout << min << endl;
}
