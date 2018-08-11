#include<iostream>
using namespace std;
#define MAX 30
#define NIL -1

struct Node {
  int parent, left, right;
};

Node T[MAX];
int D[MAX], H[MAX], S[MAX];

void setSibling(int u) {
  if (T[u].parent == NIL) {
    S[u] = -1;
  } else {
    if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) {
      S[u] = T[T[u].parent].left;
    } else if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) {
      S[u] = T[T[u].parent].right;
    } else {
      S[u] = -1;
    }
  }
}

void setDepth(int u, int d) {
  // これでuにNILが来ても安全！
  if (u == NIL) {
    return;
  }
  D[u] = d;
  // leftとrightの子どもたちは自分の深さp+1が設定される
  setDepth(T[u].left, d+1);
  setDepth(T[u].right, d+1);
}

int getHeight(int u) {
  int h1 = 0, h2 = 0;
  // 左に子がいる時
  if (T[u].left != NIL) {
    h1 = getHeight(T[u].left) + 1;
  }
  // 右に子がいる時
  if (T[u].right != NIL) {
    h2 = getHeight(T[u].right) + 1;
  }
  if (h1 > h2) {
    return H[u] = h1;
  } else {
    return H[u] = h2;
  }
}

void printNode(int u) {
  // ここで次数を計算する
  int degree = 0;
  if (T[u].left != NIL) {
    degree++;
  }
  if (T[u].right != NIL) {
    degree++;
  }
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "sibling = " << S[u] << ", ";
  cout << "degree = " << degree << ", ";
  cout << "depth = " << D[u] << ", ";
  cout << "height = " << H[u] << ", ";

  string type = "";
  if (T[u].parent == NIL) {
    type = "root";
  } else if (T[u].left != NIL || T[u].right != NIL) {
    type = "internal node";
  } else {
    type = "leaf";
  }
  cout << type << endl;
}

int main() {

  int n;
  cin >> n;
  // 初期化
  for (int i = 0; i < n; i++) {
    T[i].parent = T[i].left = T[i].right = NIL;
  }
  // 一行ずつ読み込む
  for (int i = 0; i < n; i++) {
    int v, left, right;
    cin >> v >> left >> right;
    // とりあえず左から右に受け流す〜
    // -1が入る可能性があるが、それはNIL扱い
    if (left != NIL) {
      T[v].left = left;
      T[left].parent = v;
    }
    if (right != NIL) {
      T[v].right = right;
      T[right].parent = v;
    }
  }

  int r;
  for (int i = 0; i < n; i++) {
    setSibling(i);
    if (T[i].parent == NIL) {
      r = i;
    }
  }

  setDepth(r, 0);
  getHeight(r);

  for (int i = 0; i < n; i++) {
    printNode(i);
  }

}
