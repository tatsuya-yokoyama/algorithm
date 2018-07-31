#include <iostream>
#include <list>
#include <cstring>
#include <stdio.h>

using namespace std;

list<int> L;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    char command[20];
    int key;
    scanf("%s", command);
    if (command[0] == 'i') {
      scanf("%d", &key);
      L.push_front(key);
    } else if (command[0] == 'd' && strlen(command) == 6) {
      scanf("%d", &key);
      for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        if (*it == key) {
          L.erase(it);
          break;
        }
      }
    } else if (command[0] == 'd' && command[6] == 'F') {
      L.pop_front();
    } else if (command[0] == 'd' && command[6] == 'L') {
      L.pop_back();
    }
  }
  int i = 0;
  for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
    if (i++) {
      cout << " ";
    }
    cout << *it;
  }
  cout << endl;
}
