#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  map <string, bool> T;
  string prev_str;
  cin >> n;
  cin >> prev_str;
  T[prev_str] = true;
  // cout << "--------" << endl;
  for (int i = 1; i < n; i++) {
    string current_str;
    cin >> current_str;
    // cout << "prev:" << prev_str << ", current:" << current_str << endl;
    if (prev_str[prev_str.size()-1] != current_str[0]) {
      // cout << "[no1]" << "prev:" << prev_str << "[" << prev_str[prev_str.size()-1] << "], current:" << current_str << ","<< current_str[0] << endl;
      cout << "No" << endl;
      return 0;
    }
    prev_str = current_str;
    if (T[current_str]) {
      // cout << "no2" << "prev:" << prev_str << ", current:" << current_str << endl;
      cout << "No" << endl;
      return 0;
    }
    T[current_str] = true;
  }
  cout << "Yes" << endl;
}
