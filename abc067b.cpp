#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N, K;
    vector<int> l;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        l.push_back(n);
    }
    sort(l.begin(), l.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < K; i++) {
        sum += l[i];
    }
    cout << sum << endl;
}
