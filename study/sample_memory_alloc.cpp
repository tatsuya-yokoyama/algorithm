#include <iostream>

using namespace std;

struct Node {
  int key;
};

Node *root, *NIL;

int main () {

  //
  // Node* p;
  // cout << p << endl;
  cout << root << endl;
  cout << NIL << endl;
  int *nullp = 0;
  cout << nullp << endl;

  int *nullp1 = 4321;
  cout << nullp1 << endl;

    // char* p;
    // p = (char*)malloc(sizeof(char)*4);
    //
    // p[0] = 'a';
    // p[1] = 'b';
    // p[2] = 'c';
    // p[3] = 'd';
    // // p[4], p[5]にも書き込めてしまう！
    // p[4] = 'e';
    // p[5] = 'f';
    //
    // cout << p << endl; // abcdef
    // free(p);
}
