#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> h(n), s(n);
    rep(i, n) cin >> h[i] >> s[i];
    long long right = 1LL << 63;
    long long left = 0;
    while (right - left > 1) {
        long long mid = (right - left) / 2;

        bool ok = true;
        vector<long long> t(n, 0);
        rep(i, n) {
            if (mid < h[i]) ok = false;
            else t[i] = (mid - h[i]) / s[i];
        }
        sort(t.begin(), t.end());
        rep(i, n) {
            if (i > t[i]) {
                ok = false;
            }
        }
        if (ok) right = mid;
        else left = mid;
    }
    cout << right << endl;
}