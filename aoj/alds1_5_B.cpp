#include <iostream>

using namespace std;

int L[250010];
int R[250010];
int cnt = 0;

void merge(int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = 2000000000;
  int i = 0;
  int j = 0;

  for (int k = left; k < right; k++) {
    cnt++;
    if (L[i] < R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[], int n, int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int main () {
  int n;
  cin >> n;
  int A[500010];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  mergeSort(A, n, 0, n);

  // 出力
  // 数列
  for (int i = 0; i < n; i++) {
    if (i) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;

  // 比較回数
  cout << cnt << endl;

}
