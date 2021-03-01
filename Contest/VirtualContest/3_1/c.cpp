#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long d(long long n) {
    return (long long)to_string(n).size();
}

int main() {
    long long a, b, x;
    cin >> a  >> b >> x;
    long long l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (a * mid + b * d(mid) <= x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
}
