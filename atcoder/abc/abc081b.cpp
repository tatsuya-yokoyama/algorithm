#include <iostream>

using namespace std;

int main() {
    int N;
    int A[200];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int count = 0;
    int is_even = true;
    while(is_even) {
        for (int i = 0; i < N; i++) {
            if (A[i] % 2 == 0) {
                A[i] /= 2;
            } else {
                is_even = false;
            }
        }
        if (is_even) {
            count++;
        }
    }
    cout << count << endl;
}
