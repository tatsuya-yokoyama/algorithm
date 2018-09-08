#include <iostream>

using namespace std;

int main() {
  string board[60];
  int dx[] = {1, 0,-1, 0};
  int dy[] = {0, 1, 0,-1};
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> board[i];
  }
  //cout << "--------" << endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      // まわりの爆弾を数える
      if (board[i][j] == '#') {
        //cout << "#:" << i << "," << j << "_______" << endl;
        bool is_ok = false;
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          //cout << x << "," << y << ":"<< board[i][j] << endl;
          if (x >= 0 && x < h && y >= 0 && y < w){

            if (board[x][y] == '#') {
              //cout << "got----" << endl;
              is_ok = true;
              break;
            } else {
            }
          }
        }
        if (!is_ok) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}
