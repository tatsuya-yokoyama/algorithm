#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> freq;
  for (int i = 0; i < n; i ++) {
    int num;
    cin >> num;
    if (freq.count(num) == 0) {
      freq[num] = 0;
    }
    freq[num]++;
  }
  cout << freq.size() << endl;
}
