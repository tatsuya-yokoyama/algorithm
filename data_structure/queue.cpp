#include<iostream>
#include<queue>
using namespace std;

int main() {

    queue<int> Q;

    Q.push(3);
    Q.push(2);
    Q.push(1);

    cout << Q.size() << endl;

    cout << Q.front() << endl;

    Q.pop();

    cout << Q.front() << endl;

    Q.pop();

    cout << Q.front() << endl;

}