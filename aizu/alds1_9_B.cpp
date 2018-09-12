#include <iostream>

using namespace std;

int H, A[1000000];

// ノードiを適切な場所に移動させる
void maxHeapify(int i) {
  int l, r, largest;
  l = 2 * i;
  r = 2 * i + 1;
  // left, self, rightの中で値が最大のノードをlargestに代入
  if (l <= H && A[l] > A[i]) {
    // leftのほうが大きい場合
    largest = l;
  } else {
    // 真ん中が大きい場合
    largest = i;
  }
  if (r <= H && A[r] > A[largest]) {
    // rightのほうが大きい場合
    largest = r;
  }
  // 真ん中以外がlargestのばあい、swap
  if (largest != i) {
    swap(A[largest], A[i]);
    maxHeapify(largest);
  }
}

int main() {
  cin >> H;
  for (int i = 1; i <= H; i++) {
    cin >> A[i];
  }
  for (int i = H/2; i >= 1; i--) {
    maxHeapify(i);
  }
  for (int i = 1; i <= H; i++) {
    cout << " " << A[i];
  }
  cout << endl;
}
