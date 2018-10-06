#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int>P;

int n = 10;
char A[10][10];
int color[10][10];

bool ShouldSearch(int i, int j) {
  bool should_search = true;
  // 地図の中かどうか
  if (i<0 || i>9 || j<0 | j>9) {
    // cout << i << "," << j << endl;
    should_search = false;
  }
  // 島国かどうか
  if (A[i][j] == 'x') {
    should_search = false;
  }
  // 未踏の地かどうか
  if (color[i][j] != -1) {
    should_search = false;
  }
  if (should_search) {
    return true;
  } else {
    return false;
  }
}

void Dfs(int i_s, int j_s, int color_id) {
  queue<P>Q;
  P s = make_pair(i_s, j_s);
  Q.push(s);
  while(!Q.empty()) {
    P u = Q.front(); Q.pop();
    int i = u.first;
    int j = u.second;
    color[i][j] = color_id;
    // ↑
    if (ShouldSearch(i-1, j)) {
      P v = make_pair(i-1, j);
      Q.push(v);
    }
    // →
    if (ShouldSearch(i,j+1)) {
      P v = make_pair(i, j+1);
      Q.push(v);
    }
    // ↓
    if (ShouldSearch(i+1,j)) {
      P v = make_pair(i+1, j);
      Q.push(v);
    }
    // ←
    if (ShouldSearch(i,j-1)) {
      P v = make_pair(i, j-1);
      Q.push(v);
    }
  }

}

void AssignColor() {
  // まずは初期化
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      color[i][j] = -1;
    }
  }
  int color_id = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 陸地かつ、未踏だったら探索
      if (A[i][j] == 'o' && color[i][j] == -1) {
        Dfs(i, j, color_id++);
      }
    }
  }
}

bool IsOneIland() {
  AssignColor();
  int n_iland = 0;
  int color_id = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // if (A[i][j] == 'o' && color[i][j] != -1) {
      //   cout << "i:" << i << ", j:" << j << endl;
      // }
      // if (A[i][j] == 'x') {
      //   cout << 'x';
      // }
      if (color[i][j] != -1 && color[i][j] != color_id) {
        color_id++;
        // cout << color_id;
      }
    }
    // cout << endl;
  }
  // cout << "-----------------" << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     // cout << "i:" << i << ", j:" << j << ", color:" << color[i][j] <<endl;
  //     if (color[i][j] == -1) {
  //       cout << ' ';
  //     } else {
  //       cout << color[i][j];
  //     }
  //   }
  //   cout << endl;
  // }
  // cout << "-----------------" << endl;
  //
  // cout << endl;
  // cout << ", n:" << color_id << endl;
  if (color_id == 1) {
    return true;
  } else {
    return false;
  }
}

int main() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  // 全探索
  // 海を順番に1マスずつ埋め立てして、その都度幅優先探索
  // 島が一つかどうか確かめる
  // TODO 深さ優先探索？ どちらがよい？
  // cout << "-------" << endl;
  // IsOneIland();
  // return 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 海のときだけ反転させる
      if (A[i][j] == 'x') {
        A[i][j] = 'o';
        // cout << "i:" << i << ", j:" << j;
        if (IsOneIland()) {
          cout << "YES" << endl;
          return 0;
        }
        // もとに戻す
        A[i][j] = 'x';
      }
    }
  }
  cout << "NO" << endl;
}
