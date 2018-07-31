#include <iostream>

using namespace std;

int main() {
  string board[60];
  int dx[] = {1, 1, 0,-1,-1,-1, 0, 1,1};
  int dy[] = {0, 1, 1, 1, 0,-1,-1,-1,0};
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> board[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      // まわりの爆弾を数える
      if (board[i][j] == '.') {
        int count = 0;
        for (int k = 0; k < 8; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < h && y >= 0 && y < w && board[x][y] == '#') {
            count++;
          }
        }
        board[i][j] = '0' + count;
      }

    }
  }

  // output
  for (int i = 0; i < h; i++) {
    cout << board[i] << endl;
  }
}
