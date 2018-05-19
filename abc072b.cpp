#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 1; i <= s.size(); i++) {
        if (i % 2 != 0) {
            cout << s[i-1];
        }
    }
}
