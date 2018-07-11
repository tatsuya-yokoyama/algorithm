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
  //cout << 0 << "," << W[0] << endl;
  for (int i = 1; i < N; i++) {
    W[i] = W[i-1];
    if (S[i-1] == 'W') {
      W[i]++;
    }
    //cout << i << "," << W[i] << endl;
  }
  //cout << "--------------" << endl;
  // 各iでの、それより右側でEの人の数を数える
  int E[300010];
  E[N-1] = 0;
  for (int i = N-2; i >= 0; i--) {
    E[i] = E[i+1];
    if (S[i+1] == 'E') {
      E[i]++;
    }
    //cout << i << "," << E[i] << endl;
  }

  //cout << "--------------" << endl;
  for (int i = 0; i < N; i++) {
    int count = 0;
    count = W[i] + E[i];
    if (count < min) {
      min = count;
    }
  }
  cout << min << endl;
}
