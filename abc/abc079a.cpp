#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int counter = 0;
    // 全部一致
    if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) {
        cout << "Yes";
    }
    // 0だけ違う
    else if (s[1] == s[2] && s[1] == s[3]) {
        cout << "Yes";
    }
    // 3だけ違う
    else if (s[0] == s[1] && s[0] == s[2]) {
        cout << "Yes";
    } else {
        cout << "No";
    }

}
