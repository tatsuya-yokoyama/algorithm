#include <iostream>

using namespace std;

int main() {
  int N;
  int t[100001];
  int x[100001];
  int y[100001];
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  cin >> N;
  for (int i = 1; i <= N ; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }

  bool is_ok = true;
  //cout << "-------------" << endl;
  for (int i = 0; i <= N - 1; i++) {
    int z = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
    int t_diff = t[i+1] - t[i];
    //cout << "z:" << z << ",t_diff:" << t_diff << endl;
    if (t_diff >= z) {
      if (t_diff % 2 == 0 && z % 2 == 0) {
        //cout << "even" << endl;
        is_ok = true;
      } else if (t_diff % 2 != 0 && z % 2 != 0) {
        //cout << "odd" << endl;
        is_ok = true;
      } else {
        cout << "No" << endl;
        is_ok = false;
        break;
      }
    } else {
      cout << "No" << endl;
      is_ok = false;
      break;
    }
  }
  if (is_ok) {
    cout << "Yes" << endl;
  }
}
