#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, int> T;

void CountNum(int n) {
  if (T.count(n) > 0) {
    // cout << "n:" << n << ", increment" << endl;
    T[n]++;
  } else {
    T.insert(make_pair(n, 1));
    // cout << "n:" << n << ", insert" << endl;
  }
}

int main() {
  int N;
  cin >> N;
  int n;
  vector<int> a;
  for (int i = 0; i < N; ++i) {
    cin >> n;
    a.push_back(n);
  }
  sort(a.begin(), a.end());
  
  for (int i = 0; i < N; ++i) {
    n = a[i];
    CountNum(n);
    if (n > 0) {
      CountNum(n-1);     
    }
    CountNum(n+1);
    // cout << "----------" << endl;
  }

  int max = 0;
  for(map<int, int>::iterator it = T.begin(); it != T.end(); it++) {
    pair<int, int> T = *it;
    if (T.second > max) {
      max = T.second;
    }
    // cout << "k:" << T.first << ", v:" << T.second << endl;
  }
  
  cout << max << endl;

}