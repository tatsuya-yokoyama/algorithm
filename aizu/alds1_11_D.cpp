#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// int d[10010];
int n, m;
vector<int> G[100010];
int reached[100010];
int color[100010];
int color_id = 0;

void bfs(int s, int color_id) {
  // cout << "--------------" << endl;
  // cout << "s:" << s << ", color:" << color_id <<endl;
  queue<int> Q;
  Q.push(s);
  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    // cout << "G[u].size():" << G[u].size() << endl;
    for (int i = 0; i < G[u].size(); i++) {
      // cout << u << "->" << G[u][i] << endl;
      if (reached[G[u][i]] == -1) {
        // cout << "reached at:" << G[u][i] << endl;
        Q.push(G[u][i]);
        reached[G[u][i]] = 1;
        color[G[u][i]] = color_id;
      }
    }
  }
}

void assignColor() {
  for (int i = 0; i < n; i++) {
    color[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      for (int j = 0; j < n; j++) {
        reached[j] = -1;
      }
      bfs(i, ++color_id);
    }
  }
}

int main() {
  cin >> n >> m;
  int s, t;

  // 初期化
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  // お絵かき
  assignColor();

  // 質問
  int q;
  cin >> q;
  // cout << "number of question:" << q << endl;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (color[s] == -1 || color[t] == -1) {
      cout << "no" << endl;
    } else {
      if (color[s] == color[t]) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  // お絵かきの確認
  // cout << "----------" << endl;
  //
  // for (int i = 0; i < n; i++) {
  //   cout << i << ": " << color[i] << endl;
  // }

}
