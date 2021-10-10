#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	cout << (long long)stoi(a, nullptr, k) * (long long)stoi(b, nullptr, k) << endl;
}