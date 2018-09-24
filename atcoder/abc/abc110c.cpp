#include <iostream>
#include <map>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;

  map<char, char> s2t;
  map<char, char> t2s;

  for (int i = 0; i < S.size(); i++) {

    if (s2t.count(S[i]) == 0) {
      // まだ存在しないのでset
      s2t[S[i]] = T[i];
    } else {
      if (s2t[S[i]] != T[i]) {
        cout << "No" << endl;
        return 0;
      }
      //cout << "sonzai suru:" << S[i] << " at " << s2t[S[i]] << endl;
    }
  }
  for (int i = 0; i < T.size(); i++) {

    if (t2s.count(T[i]) == 0) {
      // まだ存在しないのでset
      t2s[T[i]] = S[i];
    } else {
      if (t2s[T[i]] != S[i]) {
        cout << "No" << endl;
        return 0;
      }
      //cout << "sonzai suru:" << S[i] << " at " << s2t[S[i]] << endl;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
