#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string dton(long long m, long long n) {
    string ret = "";
    while (m > 0) {
        ret = ret + to_string(m % n);
        m /= n;
    }
    return ret;
}

int main() {
    string x;
    cin >> x;
    reverse(x.begin(), x.end());
    long long m;
    cin >> m;
    // xのうち最大値を求める
    long long d = -1;
    for (char c : x) {
        if (c - '0' > d) {
            d = c - '0';
        }
    }
    long long l = d, r = 1LL << 60;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        string s = dton(m, mid);
        cout << s << endl;
        if (x <= s) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l - d << endl;
}