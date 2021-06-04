#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> ab(n);
    rep(i, n) {
        cin >> ab[i].first;
        cin >> ab[i].second;
    }
    sort(ab.begin(), ab.end());
    long long ans = k;
    long long i = 0;
    while (i < n && ab[i].first <= ans) {
        ans += ab[i].second;
        i++;
    }
    cout << ans << endl;
}