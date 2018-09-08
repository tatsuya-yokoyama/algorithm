#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node *root, *NIL;

void preParse(Node *u) {
  if (u == NIL) {
    return;
  }
  cout << " " << u->key;
  preParse(u->left);
  preParse(u->right);
}

void inParse(Node *u) {
  if (u == NIL) {
    return;
  }
  inParse(u->left);
  cout << " " << u->key;
  inParse(u->right);
}

void insert(int k) {
  Node* y = NIL;
  Node* x = root;
  Node* z;

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->right = NIL;
  z->left = NIL;

  while(x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if ( z->key < y->key ) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

Node* find(Node *u, int k) {
  while (u != NIL && k != u->key) {
    if (k < u->key) {
      u = u->left;
    } else {
      u = u->right;
    }
  }
  return u;
}

Node * treeMinimum(Node *x) {
  while (x->left != NIL) {
    x = x->left;
  }
  return x;
}

Node * treeSuccessor(Node *x) {
  if (x->right != NIL) {
    return treeMinimum(x->right);
  }
  Node *y = x->parent;
  while( y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

void treeDelete(Node *z) {
  Node *y;
  Node *x;
  if (z->left == NIL || z->right == NIL) {
    y = z;
    // cout << "[P1] delete: " << z->key << ", y: " << y->key << endl;

  } else {

    y = treeSuccessor(z);
    // cout << "[P2] delete: " << z->key << ", y: " << y->key << endl;
  }

  // yの子xを決める
  if (y->left != NIL) {
    // cout << "[p1]" << endl;
    x = y->left;
  } else {
    // cout << "[p2]" << endl;
    x = y->right;
  }
  // 2018/09/05 このcoutを実行するようにすると、segmentation faultがおきて
  // きちんと動かない。
  // TODO 理由を調べる
  // cout << "x->key: " << x->key << endl;

  if (x != NIL) {
    x->parent = y->parent;
  }

  if (y->parent == NIL) {
    root = x;
  } else {
    if (y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }
  if (y != z) {
    z->key = y->key;
  }
  free(y);
}

int main() {
  int m;
  cin >> m;
  string command;
  for (int i = 0; i < m; i ++) {
    int x;
    cin >> command;
    if (command == "insert") {
      cin >> x;
      insert(x);
    } else if (command == "find") {
      cin >> x;
      Node* t = find(root, x);
      if (t != NIL) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    } else if (command == "delete") {
      cin >> x;
      treeDelete(find(root, x));
    } else if (command == "print") {
      inParse(root);
      cout << endl;
      preParse(root);
      cout << endl;
    }
  }
}
