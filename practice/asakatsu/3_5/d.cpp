#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long gcd(long long m, long long n) {
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }
    if (g != 1) {
        cout << "not coprime" << endl;
        return 0;
    }
}


