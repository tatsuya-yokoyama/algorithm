#include <iostream>
#include <map>

using namespace std;

int main() {
  int N, M;
  cin >> N;
  map<string, int> S, T;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    if (S.find(s) != S.end()) {
      S[s]++;
    } else {
      S[s] = 1;
    }
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> s;
    if (T.find(s) != T.end()) {
      T[s]++;
    } else {
      T[s] = 1;
    }
  }

  int score = 0;
  int max_score = 0;
  for (auto it = S.begin(); it != S.end(); it++) {
    score = it->second;
    map<string, int>::iterator itr = T.find(it->first);
    if (itr != T.end()) {
      score -= itr->second;
    }
    max_score = max(max_score, score);
  }
  cout << max_score << endl;
}
