#include <iostream>
#include <vector>

using namespace std;

int h, w;
vector<string> S;
char get_char(int i, int j);

int main() {
  cin >> h >> w;
  for(int i = 0 ; i < h; ++i) {
    string text;
    cin >> text;
    S.push_back(text);
  }
  //cout << "input done" << endl;
  //cout << h << "," << w << endl;
  //return 0;
  for(int i = 0 ; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      //cout << "(" <<i << "," << j << ") " << get_char(i,j) << " ----------" << endl;
      if (S[i][j] == '.') {
        int count = 0;
        char grid_char;
        // 上段
        //cout << "jyoudan" << endl;
        if (get_char(i-1,j-1) == '#') {
          count++;
        }
        if (get_char(i-1,j) == '#') {
          count++;
        }
        if (get_char(i-1,j+1) == '#') {
          count++;
        }

        // 中断
        //cout << "tyudan" << endl;
        if (get_char(i,j-1)) {
          count++;
        }
        if (get_char(i,j+1) == '#') {
          count++;
        }

        // 下段
        //cout << "gedan" << endl;
        if (get_char(i+1,j-1) == '#') {
          count++;
        }
        if (get_char(i+1,j) == '#') {
          count++;
        }
        if (get_char(i+1,j+1) == '#') {
          count++;
        }
        //cout << count << endl;
        S[i][j] = '0' + count;
        //cout << "after:"<< "," << S[i][j] << endl;
        //cout << "afterhoge:"<< "," << S[i] << endl;
      }
    }
  }
  //cout << "output----" << endl;
  for(int i = 0 ; i < h; ++i) {
    cout << S[i] << endl;
  }
}

char get_char(int i, int j) {
  if (i < 0 || i >= h ) {
    return '.';
  } else if (j < 0 || j >= w) {
    return '.';
  } else {
    return S[i][j];
  }
}
