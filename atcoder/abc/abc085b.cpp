#include <iostream>
#include <map>

using namespace std;

int main () {
    int N;
    cin >> N;
    map<int, int> freq;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (freq.count(n) == 0) {
            freq[n] = 1;
        } else {
            freq[n]++;
        }
    }
    cout << freq.size() << endl;
}
