#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 11;
  cout << bitset<8>(n) << endl;
  for (int i = 0; i < 8; i++) {
    if (n & (1<<i)) {
      cout << i << "th flg on" << endl;
    } else {
      cout << i << "th flg off" << endl;
    }
  }
  cout << "----------" << endl;
  // n = n | (1<<2);
  n &= ~(1<<3);

  for (int i = 0; i < 8; i++) {
    if (n & (1<<i)) {
      cout << i << "th flg on" << endl;
    } else {
      cout << i << "th flg off" << endl;
    }
  }
  //
  // for (int bit = 0; bit < (1<<n); bit++) {
  //   vector<int> S;
  //   for (int i = 0; i < n; ++i) {
  //       if (bit & (1<<i)) { // i が bit に入るかどうか
  //           S.push_back(i);
  //       }
  //   }
  //
  //   // bit の表す集合の出力
  //   cout << bit << ": {";
  //   for (int i = 0; i < (int)S.size(); ++i) {
  //       cout << S[i] << " ";
  //   }
  //   cout << "}" << endl;
  // }

  // cout << bitset<8>(n<<1) << endl;
  // cout << bitset<8>(1<<n) << endl;
  // cout << bitset<8>(1<<0) << endl;
  // cout << bitset<8>(1<<3) << endl;
  // int a = 11;
  // int b = 4;
  // cout << a << " AND " << b << " = " << (a&b) << endl;
  // cout << a << " OR " << b << " = " << (a|b) << endl;
  // // cout << a << " AND " << b << " = " << (a&b) << endl;
  // cout << bitset<8>(a) << " AND " << bitset<8>(b) << " = " << (a&b) << endl;
  // cout << bitset<8>(a) << endl;
  // cout << bitset<8>(a<<3) << endl;
  // cout << bitset<8>(1) << endl;
  // cout << bitset<8>(1<<1) << endl;
  // cout << bitset<8>(1<<2) << endl;
  // cout << bitset<8>(1<<3) << endl;
  // int n = 5;
  //
  // // {0, 1, ..., n-1} の部分集合の全探索
  // for (int bit = 0; bit < (1<<n); ++bit)
  // {
  //     /* bit で表される集合の処理を書く */
  //     vector<int> S;
  //     // cout << bit <<","<<bitset<8>(bit)<< endl;
  //     for (int i = 0; i < n; i++) {
  //       if (bit & (1<<i)) {
  //         S.push_back(i);
  //       }
  //     }
  //     // bit の表す集合の出力
  //     cout << bit << ": {";
  //     for (int i = 0; i < (int)S.size(); ++i) {
  //         cout << S[i] << " ";
  //     }
  //     cout << "}" << endl;
  // }
}
