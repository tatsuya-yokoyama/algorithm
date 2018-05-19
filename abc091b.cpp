#include <iostream>
#include <map>

using namespace std;


int main() {
	int N, M;
	cin >> N;
	map<string, int> s_map;
	map<string, int> t_map;
	string text;
	for (int i = 0; i < N; i++) {
		cin >> text;
		if (s_map.count(text) == 0) {
			s_map[text] = 1;
		} else {
			s_map[text]++;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> text;
		if (s_map.count(text) != 0) {
			s_map[text]--;
		}
	}
	int max_money = 0;
	for(auto x : s_map) {
	
		if (x.second > max_money) {
			max_money = x.second;
		}
	}
	cout << max_money << endl;
}