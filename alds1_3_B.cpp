#include <iostream>
#include<queue>
#define LEN 100010
using namespace std;

struct P {
  string name;
  int t;
};

int n, q;
queue <P> Q;

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    P p;
    cin >> p.name >> p.t;
    Q.push(p);
  }
  int elaps = 0;
  int rest = q;
  while(!Q.empty()) {
    P p = Q.front(); Q.pop();
    if (p.t > rest) {
      // プロセスが終了しない時
      elaps += rest;
      p.t -= rest;
      Q.push(p);
    } else {
      // プロセスが終了する時
      elaps += p.t;
      cout << p.name << " " << elaps << endl;
    }
  }
}
