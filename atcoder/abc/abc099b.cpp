#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
  int a, b;
  cin >> a >> b;
  int diff = b - a;
  int sum = 0;
  for (int i = 0; i <= diff; ++i) {
    sum += i;
  }
  cout << sum - b << endl;
  return 0;
}
