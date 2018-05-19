#include <iostream>

using namespace std;

int main() {
    int n, a;
    cin >> n;
    cin >> a;
    int b = n % 500;
    if (b <= a) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
