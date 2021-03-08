#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int INF = 1 << 30;

int main() {
    long long n;
    cin >> n;
    long long i = 1;
    long long ans = INF;
    while (i * i <= n) {
        if (n % i == 0) {
            long long s;
            s = max(to_string(i).size(), to_string(n / i).size());
            ans = min(ans, s);
        }
        i++;
    }
    cout << ans << endl;
}