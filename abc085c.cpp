#include <iostream>

using namespace std;

int main() {
	int N, Y;
	cin >> N >>  Y;
	// 10,000
	for (int i = 0; i <= N; i++) {
		// 5,000
		for (int j = 0; j <= N; j++) {
			int remainder = Y - 10000 * i - 5000 * j;
			if (remainder < 0) {
				continue;
			}
			int k = remainder / 1000;
			//cout << k << endl;
			if (i + j + k == N) {
				//cout << "GET====" << endl;
				cout << i << " " << j << " " << k << endl;
				return 0;
			}
		}
	}
	cout << "-1 -1 -1" << endl;
}
