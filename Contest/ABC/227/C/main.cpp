#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    long long a = 1;
    long long ans = 0;
    while (a * a <= n) {
        long long b = a;
        while (a * b * b <= n) {
            long long c = (n / a) / b;
            ans += c - b + 1;
            b++;
        }
        a++;
    }
    cout << ans << endl;
}