#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[3] == '7') {
        s[3] = '8';
    }
    cout << s;
}
