#include <iostream>

using namespace std;

int min_count(int chage);

int main() {
  int n;
  cin >> n;
  int charge = 1000 - n;
  cout << min_count(charge) << endl;
}

int min_count(int charge) {
  int count = 0;
  int total_count = 0;

  count = charge / 500;
  total_count += count;
  charge -= count * 500;

  count = charge / 100;
  total_count += count;
  charge -= count * 100;

  count = charge / 50;
  total_count += count;
  charge -= count * 50;

  count = charge / 10;
  total_count += count;
  charge -= count * 10;

  count = charge / 5;
  total_count += count;
  charge -= count * 5;

  count = charge / 1;
  total_count += count;
  charge -= count * 1;

  return total_count;
}
