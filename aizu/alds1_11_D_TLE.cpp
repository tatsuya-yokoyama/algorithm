#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// int d[10010];
int n, m;
vector<int> G[100010];
int reached[100010];

int bfs(int s, int t) {
  // cout << "--------------" << endl;
  // cout << "s:" << s << endl;
  queue<int> Q;
  Q.push(s);
  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    // cout << "G[u].size():" << G[u].size() << endl;
    for (int i = 0; i < G[u].size(); i++) {
      // cout << u << "->" << G[u][i] << endl;
      if (G[u][i] == t) {
        // cout << "[get]" << endl;
        return t;
      }
      if (reached[G[u][i]] == -1) {
        // cout << "reached at:" << G[u][i] << endl;
        Q.push(G[u][i]);
        reached[G[u][i]] = 1;
      }
    }
  }
  return -1;
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


  // 質問
  int q;
  cin >> q;
  // cout << "number of question:" << q << endl;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
      reached[i] = -1;
    }
    if (bfs(s, t) != -1) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  //
  // cout << "----------" << endl;
  //
  // for (int i = 0; i < n; i++) {
  //   cout << i << " ";
  //   for (int j = 0; j < G[i].size(); j++) {
  //     cout << G[i][j] << " ";
  //   }
  //   cout << endl;
  // }

}
