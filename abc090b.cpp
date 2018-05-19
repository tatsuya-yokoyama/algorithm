#include <iostream>

using namespace std;

bool IsPalindrome(int n) {
    int N = n;
    int a[10];
    int i = 0;
    while(n > 0) {
        a[i++] = n % 10;
        n /= 10;
    }
    if (a[0] == a[4] && a[1] == a[3]) {
        //cout << N << endl;
        return true;
    } else {
        return false;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (IsPalindrome(i)) {
            count++;
        }
    }
    cout << count << endl;

}
