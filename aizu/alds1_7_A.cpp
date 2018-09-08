#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {
  int p, l, r;
};

Node T[MAX];
int D[MAX];
int n;

void printNode(int u) {
  int i, c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "depth = " << D[u] << ", ";

  if (T[u].p == NIL) {
    cout << "root, [";
  } else if (T[u].l == NIL) {
    cout << "leaf, [";
  } else{
    cout << "internal node, [";
  }

  // 複雑に見えるが、iは単にコンマを出力するかどうかの判定に使っているだけ
  // 実質はT[u]の最も左の子供、すなわりT[u].lから右に右に兄弟をたどっていってるだけ
  for (int i = 0, c= T[u].l; c != NIL; i++, c=T[c].r) {
    // コンマ出力
    if (i) {
      cout << ", ";
    }
    cout << c;
  }
  cout << "]" << endl;
}

// ノードuに深さpをsetする関数
void rec(int u, int p) {
  D[u] = p;
  if (T[u].r != NIL) {
    rec(T[u].r, p);
  }
  if (T[u].l != NIL) {
    rec(T[u].l, p+1);
  }
}

int main() {

  cin >> n;

  // 各ノードを初期化
  for(int i = 0; i < n; i++) {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  // 入力を一行ずつ処理していく
  for(int i = 0; i < n; i++) {
    int v, d;
    cin >> v >> d;
    // それぞれの子ノードを突っ込んでいく
    int l;
    for (int j = 0; j < d; j++) {
      int c;
      cin >> c;
      if (j == 0) {
        // j=0のときだけ、
        // vの最も左の子(=l)を定義
        T[v].l = c;
      } else {
        // lのすぐ右の子(=lの兄弟)を定義
        T[l].r = c;
      }
      // 次のループ用に、lにcを代入
      l = c;
      // cの親はvだと名乗る
      T[c].p = v;
    }
  }

  int r;
  for (int i = 0; i<n; i++) {
    if (T[i].p == NIL) {
      r = i;
    }
  }
  rec(r, 0);

  for (int i = 0; i < n; i++) {
    printNode(i);
  }
}
