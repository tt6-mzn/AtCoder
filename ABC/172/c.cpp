#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m);
    rep(i, n) cin >> a.at(i);
    rep(i, m) cin >> b.at(i);
    vector<long long> sum_a(n + 1), sum_b(m + 1); // sum_a[i] = 上からi - 1まで読むときの所要時間
    sum_a.at(0) = 0;
    sum_b.at(0) = 0;
    for(int i = 1; i < n + 1; i++) {
        sum_a.at(i) = sum_a.at(i - 1) + a.at(i - 1);
    }
    for(int i = 1; i < m + 1; i++) {
        sum_b.at(i) = sum_b.at(i - 1) + b.at(i - 1);
    }
    long long i = 0, j = 0, ans = 0;
    while(i < n + 1 && sum_a.at(i) <= k) i++;
    i--;
    while(0 <= i && j < m + 1) {
        while(j < m + 1 && sum_a.at(i) + sum_b.at(j) <= k) j++;
        j--;
        ans = max(ans, i + j);
        i--;
    }
    cout << ans << endl;
}