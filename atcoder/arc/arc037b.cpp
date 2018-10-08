#include <iostream>
#include <queue>
#include <stack>

using namespace std;
typedef pair<int,int>P;

int N, M;
int A[110][110];
int reached[110];
int n_tree = 0;

bool should_increment = false;

void dfs(int u, int prev) {
  reached[u] = 1;
  for (int v = 0; v < N; v++) {
    if (A[u][v] == 1) {
      if (v != prev) {
        if (reached[v] == 0) {
          dfs(v, u);
        } else {
          should_increment = false;
        }
      }
    }
  }
}

void GetNumTree() {
  for (int i = 0; i < N; i++) {
    // まだ探索してない頂点を発見する=新しいグラフの発見
    if (reached[i] == 0){
      should_increment = true;
      dfs(i, -1);
      if (should_increment) {
        n_tree++;
      }
    }
  }
}

int main() {
  // init
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = 0;
    }
  }
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    A[u-1][v-1] = 1;
    A[v-1][u-1] = 1;
  }

  for (int i = 0; i < N; i++) {
    reached[i] = 0;
  }

  GetNumTree();
  cout << n_tree << endl;
}
