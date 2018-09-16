#include <iostream>
#include <complex>

using namespace std;

bool isPrime(int n) {
  if (n == 2) {
    return true;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool like2017(int n) {
  if (n == 2017) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  if (!isPrime(n)) {
    return false;
  }
  if (!isPrime((n+1)/2)) {
    return false;
  }
  return true;
}

int main() {
  int Q;
  int l[100010], r[1000010], s[100010];
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> l[i] >> r[i];
  }
  // 累積和s[i]を求める
  // s[i] = 0からiまでの間で、2017に似た奇数の個数
  s[0] = 0;
  for (int i = 2; i < 100005; i++) {
    s[i] = s[i-1];
    if (like2017(i)) {
      s[i]++;
    }
    // cout << "i:" << i << ", s[i]:" << s[i] << endl;
  }

  for (int i = 0; i < Q; i++) {
    // cout << "s[r[i]]:" << s[r[i]] << ", s[l[i]]:" << s[l[i]] << endl;
    cout << s[r[i]] - s[l[i]-1] << endl;
  }

}
