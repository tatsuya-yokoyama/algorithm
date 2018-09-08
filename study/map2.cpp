#include <iostream>
#include <map>

using namespace std;

void print(map<string, int> T) {
  map<string, int>::iterator it;
  cout << "-------------" << endl;
  cout << "size:" << T.size() << endl;
  for (it = T.begin(); it != T.end(); it++) {
    pair<string, int> item = *it;
    cout << item.first << "-->" << item.second << endl;
  }
}

int main() {
  map<string, int> T;
  T["red"] = 32;
  T["blue"] = 688;
  T["yellow"] = 122;

  T["blue"] += 312;

  print(T);

  T.insert(make_pair("zebra", 92134));
  T.insert(make_pair("white", 92134));

  print(T);

  T.erase("yellow");

  print(T);

  pair<string, int> target = *T.find("reds");
  cout << "find:" << target.first << "-->" << target.second << endl;

  // print(T);

}
