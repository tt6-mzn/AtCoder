#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n = 1048576;
    long long q;
    cin >> q;
    vector<long long> a(n, -1);
    vector<long long> tmp(n + 1);
    rep(i, n + 1) tmp[i] = i;
    set<long long> st(tmp.begin(), tmp.end());
    rep(i, q) {
        long long t, x;
        cin >> t >> x;
        if (t == 1) {
            auto it = st.lower_bound(x % n);
            long long index = *it;
            if (index == n) {
                it = st.lower_bound(0);
                index = *it;
            }
            a[index] = x;
            st.erase(index);
        }
        else {
            cout << a[x % n] << endl;
        }
    }
}