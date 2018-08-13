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

void inParse(int u) {
  if (u == NIL) {
    return;
  }
  inParse(T[u].l);
  cout << " " << u;
  inParse(T[u].r);
}

void postParse(int u) {
  if (u == NIL) {
    return;
  }
  postParse(T[u].l);
  postParse(T[u].r);
  cout << " " << u;
}

int main() {
  cin >> n;

  // 初期化
  for (int i = 0; i < n; i++) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
  // 入力
  for (int i = 0; i < n; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    T[v].l = l;
    T[v].r = r;
    if (l != NIL) {
      T[l].p = v;
    }
    if (r != NIL) {
      T[r].p = v;
    }
  }

  // ルート求める
  int root;
  for (int i = 0; i < n; i++) {
    int r;
    if (T[i].p == NIL) {
      root = i;
      // cout << "root at " << root << endl;
      break;
    }
  }
  // cout << "root:" << root << endl;
  cout << "Preorder" << endl;
  preParse(root);
  cout << endl;

  cout << "Inorder" << endl;
  inParse(root);
  cout << endl;
  //
  cout << "Postorder" << endl;
  postParse(root);
  cout << endl;
  return 0;

}
