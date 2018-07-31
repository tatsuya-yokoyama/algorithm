#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

struct Node {
  int key;
  Node *prev, *next;
};

Node *nil;

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  // x
  x->key = key;
  x->next = nil->next;
  x->prev = nil;
  // xの次
  nil->next->prev = x;
  // nilの次
  nil->next = x;
}

void deleteNode(Node *t) {
  // tが番兵の場合は処理しない
  if (t == nil) {
    return;
  }
  // tの前
  t->prev->next = t->next;
  // tの次
  t->next->prev = t->prev;
  // 解放
  free(t);
}

void deleteFirst() {
  deleteNode(nil->next);
}

void deleteLast() {
  deleteNode(nil->prev);
}

Node* listSearch(int key) {
  Node *cur = nil->next;
  while(cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void deleteKey(int key) {
  deleteNode(listSearch(key));
}

void printList() {
  Node *cur = nil->next;
  while(cur != nil) {
    cout << cur->key;
    if (cur->next != nil) {
      cout << " ";
    }
    cur = cur->next;

  }
  cout << endl;
}

int main() {
  init();
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    char command[20];
    int key;
    scanf("%s", command);
    if (command[0] == 'i') {
      scanf("%d", &key);
      insert(key);
    } else if (command[0] == 'd' && strlen(command) == 6) {
      scanf("%d", &key);
      deleteKey(key);
    } else if (command[0] == 'd' && command[6] == 'F') {
      deleteFirst();
    } else if (command[0] == 'd' && command[6] == 'L') {
      deleteLast();
    }
  }
  printList();
}
