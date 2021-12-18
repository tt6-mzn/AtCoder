#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long f(long long x, vector<long long> &a) {
    // xを支払うのに必要な硬貨の枚数の最小
    long long ret = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] > x) continue;
        ret += x / a[i];
        x %= a[i];
    }
    return ret;
}

int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    cout << f(x, a) << endl;
    return 0;
}