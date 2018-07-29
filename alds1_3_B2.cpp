#include <iostream>
#define LEN 100010
using namespace std;

struct P {
  string name;
  int time;
};

int head, tail;
int n, q;
P Q[LEN];

void enqueue(P p) {
  Q[tail] = p;
  tail = (tail + 1) % LEN;
}

P dequeue() {
  P p = Q[head];
  head = (head + 1) % LEN;
  return p;
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> Q[i].name >> Q[i].time;
  }
  head = 0;
  tail = n;
  int elaps = 0;
  int rest = q;
  while(head != tail) {
    P p = dequeue();
    if (p.time > rest) {
      // プロセスが終了しない時
      elaps += rest;
      p.time -= rest;
      enqueue(p);
    } else {
      // プロセスが終了する時
      elaps += p.time;
      cout << p.name << " " << elaps << endl;
    }
  }
}
