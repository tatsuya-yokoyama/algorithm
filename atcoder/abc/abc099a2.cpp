#include<iostream>

using namespace std;

bool IsGreaterThan999(int num) {
    if (num > 999) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    if (IsGreaterThan999(N)) {
        cout << "ABD" << endl;
    } else {
        cout << "ABC" << endl;
    }
    return 0;
}