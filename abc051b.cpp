#include <iostream>

using namespace std;

int main() {
    int k, s;
    cin >> k >> s;
    int count = 0;
    int should_break = false;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int z = s - i - j;
            if (z >= 0 && z <= k) {
                count ++;
            }
        }
    }
    cout << count;

}
