#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count_max = 0;
    int num_max = 1;
    for (int i = 1; i <= n; i++) {

        int num = i;
        int count = 0;
        while(num % 2 == 0) {
            num /= 2;
            count++;
        }
        if (count > count_max) {
            count_max = count;
            num_max = i;
        }
    }
    cout << num_max;
}
