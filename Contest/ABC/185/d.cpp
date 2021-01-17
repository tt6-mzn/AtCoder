#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end(), greater<long long>());

    vector<long long> a_add(n);
    a_add.at(n - 1) = a.at(n - 1);
    for(int i = n - 2; i > 0; i--) {
        a_add.at(i) = a_add.at(i + 1) + a.at(i);
    }

    long long ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += (n - i - 1) * a.at(i) - a_add.at(i + 1);
    }
    cout << ans << endl;
}