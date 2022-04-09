#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int s = 0;
    rep(i, n) s += a[i];
    sort(a.begin(), a.end(), greater<int>());
    rep(i, m) {
        if (4 * m * a[i] < s) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}