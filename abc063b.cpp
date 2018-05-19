#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    string ans = "yes";
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && s[i] == s[j]) {
                ans = "no";
                break;
            }
        }
    }
    cout << ans << endl;

}
