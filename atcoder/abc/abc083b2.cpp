#include <iostream>

using namespace std;

int getDigitsSum(int number) {
  int sum = 0;
  while(1) {
    int rest = number % 10;
    sum += rest;
    number /= 10;
    //cout << i << "," << sum << "," << rest << "," << number << endl;
    if (number == 0) {
      break;
    }
  }
  return sum;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int total = 0;
  for (int i = 1; i <= n; i++) {
    int sum = getDigitsSum(i);
    if (sum >= a && sum <= b) {
      //cout << "get" << endl;
      total += i;
    }
  }
  cout << total << endl;
}
