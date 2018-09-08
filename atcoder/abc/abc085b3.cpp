#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int,int> freq;
  for (int i = 0; i < n; i++) {
    int number;
    cin >> number;
    if (freq.count(number) == 0) {
      freq[number] = 0;
    }
    freq[number]++;
  }
  cout << freq.size() << endl;
}
