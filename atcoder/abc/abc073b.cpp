#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int l;
        int r;
        cin >> l;
        cin >> r;
        int num = r - l + 1;
        sum += num;
    }
    cout << sum;
}
