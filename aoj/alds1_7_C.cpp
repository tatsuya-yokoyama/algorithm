#include<iostream>
using namespace std;
#define MAX 30
#define NIL -1


struct Node {
  int p,l,r;
};

int n;
Node T[MAX];

void preParse(int u) {
  if (u == NIL) {
    return;
  }
  cout << " " << u;
  preParse(T[u].l);
  preParse(T[u].r);
}

void postParse(int u) {
  if (u == NIL) {
    return;
  }
  if (T[u].p !+ NIL) {
    
  }

}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
  for (int i = 0; i < n; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    if (l != NIL) {
      T[v].l = l;
      T[l].p = v;
    }
    if (r != NIL) {
      T[v].r = r;
      T[r].p = v;
    }
  }

  int r;
  for (int i = 0; i < n; i++) {
    int r;
    if (T[i].p == NIL) {
      r = i;
    }
  }

  cout << "Preorder" << endl;
  preParse(r);
  cout << endl;

  cout << "+Preorder" << endl;
  preParse(r);
  cout << endl;

  cout << "-Preorder" << endl;
  preParse(r);
  cout << endl;
  return 0;

}
