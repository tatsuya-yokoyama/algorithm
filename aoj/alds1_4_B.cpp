#include <iostream>

using namespace std;

int n, q;
int S[10010];
int T[510];

int binarySearch(int x) {
  int left = 0;
  int right = n;
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (S[mid] == x) {
      return mid;
    } else if (x < S[mid]){
      // cout << "[p1] l:" << left << ", m:" << mid << ", r:" << right << endl;
      right = mid;
    } else {
      left = mid + 1;
      // cout << "[p2] l:" << left << ", m:" << mid << ", r:" << right << endl;
    }
  }
  return -1;
}

int binarySearch2(int key) {
  int left = 0;
  int right = n;
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (key == S[mid]) return mid;
    if (key > S[mid]) left = mid + 1;
    else if (key < S[mid]) right = mid;
  }
  return -1;
}

int binSearch(int key) {
  int first = 0, last = n, middle;

  while (first < last) {
    middle = (first + last) / 2;
    if (key == S[middle]) return 1;
    if (key > S[middle]) first = middle+1;
    else if (key < S[middle]) last=middle;
  }

  return -1;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> T[i];
  }
  int sum = 0;
  for (int i = 0; i < q; i++) {
    int ret = binSearch(T[i]);
    if (ret != -1) {
      sum++;
    }
  }
  cout << sum << endl;
}
