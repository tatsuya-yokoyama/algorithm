#include <iostream>

using namespace std;

int main() {
  int N;
  int a[110];
  int count = 0;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  for(int i = 1; i < N; i++) {
    if (a[i] == a[i-1]) {
      count++;
      i++;
    }
  }
  cout << count << endl;
}
