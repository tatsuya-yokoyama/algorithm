#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int>P;

int R, C;
int x_s, y_s;
int x_g, y_g;
char c[51][51];
int d[51][51];

int reached[51][51];

void bfs() {
  // 初期化
  for (int y = 1; y < R+1; y++) {
    for (int x = 1; x < C+1; x++) {
      reached[x][y] = 0;
      d[x][y] = -1;
    }
  }

  queue<P>Q;
  P s = make_pair(x_s, y_s);
  d[x_s][y_s] = 0;

  Q.push(s);
  // cout << "(" << x_s << "," << y_s << ")" << endl;
  while(!Q.empty()) {
    P u = Q.front(); Q.pop();
    int x = u.first;
    int y = u.second;
    // 右
    int x_n = -1;
    int y_n = -1;

    if (c[x+1][y] == '.' && d[x+1][y] == -1) {
      x_n = x+1;
      y_n = y;
      P v = make_pair(x_n, y_n);
      Q.push(v);
      d[x_n][y_n] = d[x][y] + 1;
      // cout << "right:" << "(" << x << "," << y << ") -> (" << x_n << ","  << y_n << ")" << endl;
    }
    // 下
    if (c[x][y+1] == '.' && d[x][y+1] == -1) {
      x_n = x;
      y_n = y+1;
      P v = make_pair(x_n, y_n);
      Q.push(v);
      d[x_n][y_n] = d[x][y] + 1;
      // cout << "down :" << "(" << x << "," << y << ") -> (" << x_n << ","  << y_n << ")" << endl;
    }
    // 左
    if (c[x-1][y] == '.' && d[x-1][y] == -1) {
      x_n = x-1;
      y_n = y;
      P v = make_pair(x_n, y_n);
      Q.push(v);
      d[x_n][y_n] = d[x][y] + 1;
      // cout << "left :" << "(" << x << "," << y << ") -> (" << x_n << ","  << y_n << ")" << endl;
    }
    // 上
    if (c[x][y-1] == '.' && d[x][y-1] == -1) {
      x_n = x;
      y_n = y-1;
      P v = make_pair(x_n, y_n);
      Q.push(v);
      d[x_n][y_n] = d[x][y] + 1;
      // cout << "up   :" << "(" << x << "," << y << ") -> (" << x_n << ","  << y_n << ")" << endl;
    }
  }
}

int main() {
  cin >> R >> C;
  cin >> y_s >>  x_s;
  cin >> y_g >>  x_g;

  for (int y = 1; y < R+1; y++) {
    string row;
    cin >> row;
    for (int x = 1; x < C+1; x++) {
      c[x][y] = row[x-1];
    }
  }

  bfs();

  cout << d[x_g][y_g] << endl;

  // cout << "---------" << endl;
  //
  // for (int y = 1; y < R+1; y++) {
  //   for (int x = 1; x < C+1; x++) {
  //     cout << "(" << x << "," << y << "):" << d[x][y] << endl;
  //   }
  // }
}
