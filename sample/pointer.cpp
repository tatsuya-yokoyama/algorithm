#include <iostream>

using namespace std;


void twice(int *a) {
  if (a == nullptr) {
    cout << "null" << endl;
    return;
  }
  cout << *a << endl;
  *a *= 2;
  cout << *a << endl;
}


void hoge(int a[]) {
  a[0] = 85432;
}

int main() {
  twice(nullptr);
  int v = 16;
  cout << v << endl;
  twice(&v);
  cout << v << endl;

  // int arr[3];
  // int* p;
  // arr[0] = 1110;
  // arr[1] = 1111;
  // arr[2] = 1112;
  // // p = arr;
  // // cout << p[1];
  //
  // cout << arr[0] << "," << arr[1] << "," << arr[2] << endl;
  // hoge(arr);
  // cout << arr[0] << "," << arr[1] << "," << arr[2] << endl;



  //
  // int a, b;
  // int *p;
  // a = 100;
  // b = 200;
  // p = &a;
  // cout << *p;

}
