#include <iostream>
#define M 5

using namespace std;

int H[M];

int h1(int key) {
  return key % M;
}

int h2(int key) {
  return 1 + (key % (M));
}

void insert(int key) {
  for (int i = 0; ; i++) {
    int h = (h1(key) + i * h2(key)) % M;

    if (H[h] == key) {
      cout << "[ar] i:" << i <<", h:" << h << endl;
      break;
    } else if (H[h] != 0) {
      cout << "[ng] i:" << i <<", h:" << h << endl;
    } else {
      H[h] = key;
      cout << "     i:" << i <<", h:" << h << endl;
      break;
    }
    if (i >= M) {
      cout << "ippai dayo!!" << endl;
      break;
    }
  }
}

int main() {
  int num;
  while(cin >> num) {
    insert(num);
  }
}
