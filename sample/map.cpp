#include <iostream>
#include <map>

using namespace std;

void print(map<string, int> T) {
  cout << T.size() << endl;
  for (auto it = T.begin(); it != T.end(); it++) {
    cout << it->first << " --> " << it->second << endl;
  }
}

int main() {
  map<string, int> T;
  T["red"] = 32;
  T["blue"] = 688;
  T["yellow"] = 122;

  print(T);

  T["blue"] += 4353;

  print(T);

  T.insert(make_pair("zebra", 10423));
  T.insert(make_pair("white", 1444));

  cout << "-------------" << endl;
  print(T);
  cout << "-------------" << endl;

  pair<string, int> target = *T.find("red");
  cout << target.first << " --> " << target.second << endl;
}
