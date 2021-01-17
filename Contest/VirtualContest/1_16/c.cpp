#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i, m) cin >> x[i];
    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());
    vector<int> d(m - 1);
    for (int i = 0; i < m - 1; i++) d[i] = x[i + 1] - x[i];
    sort(d.begin(), d.end(), greater<int>());
    int t = 0;
    rep(i, n - 1) t += d[i];
    cout << (x[m - 1] - x[0]) - t << endl;
}