#include <iostream>
#define M 1000010

using namespace std;

int H[M];

int char2Int(char c) {
  if (c == 'A') return 1;
  else if (c == 'C') return 2;
  else if (c == 'G') return 3;
  else if (c == 'T') return 4;
  else return 0;
}

int getKey(string str) {
  int sum = 0;
  int p = 1;
  for (int i = 0; i < str.size(); i++) {
    int char2int = char2Int(str[i]);
    int add = p * char2int;
    sum += add;
    p *= 5;
  }
  return sum;
}

int h1(int key) {
  return key % M;
}

int h2(int key) {
  return 1 + (key % (M));
}

void insert(string str) {
  int key = getKey(str);
  for (int i = 0; ; i++) {
    int h = (h1(key) + i * h2(key)) % M;

    if (H[h] == key) {
      // cout << "[aready] i:" << i <<", h:" << h << endl;
      break;
    } else if (H[h] != 0) {
      // cout << "[collision] i:" << i <<", h:" << h << endl;
    } else {
      H[h] = key;
      // cout << "[insert!] i:" << i <<", h:" << h << endl;
      break;
    }
    if (i >= M) {
      cout << "hash full" << endl;
      break;
    }
  }
}

int find(string str) {
  int key = getKey(str);
  for (int i = 0; ; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (H[h] == key) {
      // cout << "[aready] i:" << i <<", h:" << h << endl;
      return h;
    } else if (H[h] != 0) {
      // cout << "[collision] i:" << i <<", h:" << h << endl;
    } else {
      return -1;
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string command;
    string str;
    cin >> command >> str;
    // cout << command << endl;
    if (command == "insert") {
      // cout << "insert" << endl;
      insert(str);
    } else if (command == "find") {
      if (find(str) != -1) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
}
