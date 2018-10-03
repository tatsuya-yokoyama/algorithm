#include <iostream>
#include <vector>

using namespace std;

int main() {
  // vector<int> V;
  // V.push_back(1192);
  // V.push_back(1601);
  // V.push_back(1864);
  // for (int x : V) {
  //   cout << x << endl;
  // }

  vector<int> G[100];

  int a[10];
  a[0] = 32;
  a[1] = 4321;
  G[32].push_back(232);
  G[32].push_back(101);
  G[32].push_back(1);

  for (int i = 0; i <= 2; i++) {
    cout << G[32][i] << endl;
  }
}
