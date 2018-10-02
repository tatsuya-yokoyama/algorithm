#include <iostream>
#include <map>

using namespace std;

int odd_max_num_key;
int odd_second_max_num_key;
int odd_max_num_value;
int odd_second_max_num_value;

int even_max_num_key;
int even_second_max_num_key;
int even_max_num_value;
int even_second_max_num_value;

void get_max_and_second_max(map<int, int> m, string type) {
  int max_num_key = -1;
  int max_num_value = 0;
  int second_max_num_key = -1;
  int second_max_num_value = 0;

  // 一番個数が大きい数を求める
  for(auto itr = m.begin(); itr != m.end(); ++itr) {
    // std::cout << "key = " << itr->first << ", val = " << itr->second << "\n";
    int key = itr->first;
    int value = itr->second;
    if (value > max_num_value) {
      max_num_key = key;
      max_num_value = value;
    }
  }

  // 二番目に個数が大きい数を求める
  for(auto itr = m.begin(); itr != m.end(); ++itr) {
    // std::cout << "key = " << itr->first << ", val = " << itr->second << "\n";
    int key = itr->first;
    int value = itr->second;
    // すでに一番個数が大きい数認定されてるやつはスルー
    if (key == max_num_key) {
      continue;
    }
    if (value > second_max_num_value) {
      second_max_num_key = key;
      second_max_num_value = value;
    }
  }

  if (type == "odd") {
    odd_max_num_key = max_num_key;
    odd_second_max_num_key = second_max_num_key;
    odd_max_num_value = max_num_value;
    odd_second_max_num_value = second_max_num_value;
  } else {
    even_max_num_key = max_num_key;
    even_second_max_num_key = second_max_num_key;
    even_max_num_value = max_num_value;
    even_second_max_num_value = second_max_num_value;
  }
}

int main() {
  int n;
  int v[100010];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  // for (int i = 0; i < n; i++) {
  //   cout << v[i] << endl;
  // }
  // 全部同じパターン
  bool all_same = true;
  for (int i = 1; i < n; i++) {
    // cout << "v[i-1]:" << v[i-1] << ", v[i]:" << v[i] << endl;
    if (v[i-1] != v[i]) {
      all_same = false;
    }
  }
  if (all_same) {
    // cout << "same" << endl;
    cout << n/2 << endl;
    return 0;
  }


  // odd
  map<int, int> m_odd;
  for (int i = 0; i < n; i += 2) {
    // cout << i << endl;
    if (m_odd.count(v[i]) == 0) {
      m_odd[v[i]] = 0;
    }
    m_odd[v[i]]++;
  }
  get_max_and_second_max(m_odd, "odd");
  // cout << "[odd]" << endl;
  // cout << "max:" << odd_max_num_key << " -> " << odd_max_num_value << endl;
  // cout << "2th:" << odd_second_max_num_key << " -> " << odd_second_max_num_value << endl;


  // even
  map<int, int> m_even;
  for (int i = 1; i < n; i += 2) {
    // cout << i << endl;
    if (m_even.count(v[i]) == 0) {
      m_even[v[i]] = 0;
    }
    m_even[v[i]]++;
  }
  get_max_and_second_max(m_even, "even");
  // cout << "[even]" << endl;
  // cout << "max:" << even_max_num_key << " -> " << even_max_num_value << endl;
  // cout << "2th:" << even_second_max_num_key << " -> " << even_second_max_num_value << endl;


  int sum = 0;
  if (odd_max_num_key == even_max_num_key) {
    // TODO
    // oddのほうがより多い場合、evenはmaxを使って、oddは二番目を使う
    if (odd_second_max_num_value > even_second_max_num_value) {
      int odd_num = n/2 - odd_second_max_num_value;
      int even_num = n/2 - even_max_num_value;
      sum = odd_num + even_num;
    } else {
      // その逆
      int odd_num = n/2 - odd_max_num_value;
      int even_num = n/2 - even_second_max_num_value;
      sum = odd_num + even_num;
    }
  } else {
    int odd_num = n/2 - odd_max_num_value;
    int even_num = n/2 - even_max_num_value;
    sum = odd_num + even_num;
  }

  cout << sum << endl;
}
