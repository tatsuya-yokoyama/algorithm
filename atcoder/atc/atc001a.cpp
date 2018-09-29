#include <iostream>
#define W_MAX 510
#define H_MAX 510

using namespace std;

int H, W;
int x_s, y_s, x_g, y_g;
char maze[W_MAX][H_MAX];
bool reached[W_MAX][H_MAX];
bool can_reach = false;

void search(int x, int y) {
  // (x,y)が迷路の外、もしくは塀
  if (x < 0 || x > W-1 || y < 0 || y > H-1 || maze[x][y] == '#') {
    return;
  }
  // すでに到達している
  if (reached[x][y]) {
    return;
  }
  reached[x][y] = true;
  // 到達
  // cout << "(" << x << ", " << y << ')' << endl;
  if (maze[x][y] == 'g') {
    // cout << "goal at (" << x << ", " << y << ')' << endl;
    can_reach = true;
    return;
  }
  search(x+1,y); // 右
  search(x-1,y); // 左
  search(x,y+1); // 上
  search(x,y-1); // 下
}

int main() {
  cin >> H >> W;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      reached[x][y] = false;
      // cout << "(" << x << ", " << y << ")" << endl;
    }
  }


  char c;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> maze[x][y];
      if (maze[x][y] == 's') {
        x_s = x;
        y_s = y;
      }
      if (maze[x][y] == 'g') {
        x_g = x;
        y_g = y;
      }
    }
  }

  // スタートの座標から呼び出す
  search(x_s, y_s);

  if (can_reach) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
