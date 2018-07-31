#include <iostream>

using namespace std;

int main() {
  int count_total = 0; // 合計
  int count_1 = 0; // 直角三角形
  int count_2 = 0; // 鋭角
  int count_3 = 0; // 鈍角
  while(true) {
    int long_side = 0;
    int short_side1 = 0;
    int short_side2 = 0;
    int a, b, c = 0;
    cin >> a >> b >> c;
    if (!(abs(b-c) < a && a < b + c)) {
      //cout << "-----" << endl;
      cout << count_total << " " << count_1 << " " << count_2 << " " << count_3 << endl;
      return 0;
    }
    count_total++;
    int max_side = a;
    if (b > a && b > c) {
      // bが一番長い
      long_side = b;
      short_side1 = a;
      short_side2 = c;
    } else if (c > a && c > b) {
      // cが一番長い
      long_side = c;
      short_side1 = a;
      short_side2 = b;
    } else {
      // aが一番長い
      long_side = a;
      short_side1 = b;
      short_side2 = c;
    }
    int d1 = long_side * long_side;
    int d2 = short_side1 * short_side1 + short_side2 * short_side2;
    // 鈍角
    if (d1 > d2) {
      count_3++;
    } else if (d1 == d2) {
      // 直角
      count_1++;
    } else {
      // 鋭角
      count_2++;
    }
  }

}
