#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a.at(i);
    vector<long long> sum_a(n + 1);
    sum_a.at(0) = a.at(0);
    for(int i = 1; i < n; i++) sum_a.at(i) = a.at(i)+sum_a.at(i-1);

    long long ans = 0, max_a = sum_a.at(0), now = sum_a.at(0);
    ans = max(ans, sum_a.at(0));
    max_a = max(max_a, sum_a.at(1));
    for(int i = 1; i < n; i++) {
        ans = max(ans, now + max_a);
        max_a = max(max_a, sum_a.at(i + 1));
        now += sum_a.at(i);
    }
    cout << ans << endl;
}