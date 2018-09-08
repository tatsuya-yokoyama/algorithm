#include <iostream>
#include <vector>

using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int> a;
    for (int i = 0 ; i < N; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end(), greater<int>());
    int alice = 0;
    int bob = 0;
    for (int i = 0; i < N; i++) {
        int num = a.front();
        a.erase(a.begin());
        if (i % 2 == 0) {
            alice += num;
        } else {
            bob += num;
        }
    }
    cout << alice - bob << endl;

}
