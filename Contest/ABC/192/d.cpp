#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string dton(long long m, long long n) {
    string ret = "";
    while (m > 0) {
        ret += to_string(m % n) + ret;
        m /= n;
    }
    return ret;
}

long long ntod(string x, long long n) {
    long long ret = 0;
    long long d = 1;
    for (int i = x.size() - 1; i >= 0; i--) {
        if (ret + (x [i] - '0') * d < 0) {
            return 1LL << 62;
        }
        ret += (x[i] - '0') * d;
        d *= n;
    }
    return ret;
}

int main() {
    string x;
    cin >> x;
    long long m;
    cin >> m;
    long long d = -1;
    for (char c : x) {
        if (c - '0' > d) {
            d = c - '0';
        }
    }
    long long l = d + 1, r = 1LL << 62;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (ntod(x, mid) <= m) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l - d << endl;
}


