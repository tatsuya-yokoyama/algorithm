#include <iostream>
#include <map>

using namespace std;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string a;
    cin >> a;
    map<char, int> alphabet_map;

    for(int i = 0; i < a.size(); i++) {
        if (alphabet_map.count(a[i]) == 0) {
            alphabet_map[a[i]] = 1;
        }
    }
    char min_alphabet;
    for (int i = 0; i < alphabet.size(); i++) {
        if (alphabet_map.count(alphabet[i]) == 0) {
            min_alphabet = alphabet[i];
            cout << min_alphabet << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}
