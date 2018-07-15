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
  for (int i = 0; i < 100000000; i++) {
    if (i > 0 && count == A) {
      return true;
    }
    if (count < B) {
      return false;
    }
    cout << "[" << i << "]" << "[in]"<< count << endl;
    // B個買う
    count -= B;
    cout << "[" << i << "]" << "[-" << B << "]" << count << endl;
    // C本以下なら補充
    if (count <= C) {
      count += D;
      cout << "[" << i << "]" << "[+" << D << "]" << count << endl;
    }
  }
  return true;
}
