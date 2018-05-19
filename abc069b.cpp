#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    cout << s[0];
    cout << n - 2;
    cout << s[n-1];
}
