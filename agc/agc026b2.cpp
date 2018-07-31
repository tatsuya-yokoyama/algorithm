#include <iostream>

using namespace std;

bool can_continue(long long A, long long B, long long C, long long D);

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    //cout << i << "read!" << A << "," << B << "," << C << "," << D << endl;
    //cout << A << "," << B << "," << C << "," << D << endl;
    if (can_continue(A, B, C, D)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}


bool can_continue(long long A, long long B, long long C, long long D) {
  cout << "-------------" << endl;
  cout << A << "," << B << "," << C << "," << D << endl;
  long long count = A;
  if (A < B) {
    return false;
  }
  long long rest = A % B;
  long long sabun = (D-B);
  long long shou = (C - rest) / sabun;
  long long hantei;
  if (C <= rest) {
    hantei = sabun;
  } else {
    hantei = shou * (C - rest) + shou;
  }
  cout << rest << "," << sabun << "," << shou << "," << hantei << endl;
  if (hantei >= B) {
    return true;
  } else {
    return false;
  }
}
