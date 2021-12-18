#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    if (n >= 42) cout << "AGC0" << n + 1 << endl;
    else if (n >= 10) cout << "AGC0" << n << endl;
    else cout << "AGC00" << n << endl;
    return 0;
}