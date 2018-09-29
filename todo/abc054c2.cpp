#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100][100];
string color[100];

int P[10];

void dfs(int pos, int mask) {
  // permutationが最後まで見つかった
  if (pos == N) {
    // TODO 見つかったときの操作をする
    return;
  }
  for (int i = 0; i < N; i++) {
    if (mask && (1<<i)) {
      P[pos] = i;
      dfs(pos+1, (mask^(1<<i)));
    }
  }

}


int main() {
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = 0;
    }
  }
  // for (int i = 0; i < N; i++) {
  //   color[i] = "WHITE";
  // }
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    A[a-1][b-1] = 1;
    A[b-1][a-1] = 1;
    // A[a][b] = 1;
    // A[b][a] = 1;
  }
  int p[N];
  for (int i = 0; i < N; i++) {
    p[i] = i;
  }
  int count = 0;
  dfs(0, (1<<N)-1);
  cout << count << endl;
}
