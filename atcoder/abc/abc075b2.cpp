#include <iostream>

using namespace std;

int main() {
  string board[60];
  int dx[] = {1, 1, 0,-1,-1,-1, 0, 1};
  int dy[] = {0, 1, 1, 1, 0,-1,-1,-1};
  int X, Y;
  cin >> X >> Y;
  for(int i = 0 ; i < X; ++i) {
    cin >> board[i];
  }
  for(int i = 0 ; i < X; ++i) {
    for(int j = 0 ; j < Y; ++j) {
      if (board[i][j] == '.') {
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < X && y >= 0 && y < Y && board[x][y] == '#') {
            cnt++;
          }
        }
        board[i][j] = '0' + cnt;
      }
    }
  }
  for(int i = 0 ; i < X; ++i) {
    cout << board[i] << endl;
  }
}
