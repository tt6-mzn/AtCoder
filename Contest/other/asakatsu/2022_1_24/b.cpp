#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> c(m);
    rep(i, m) cin >> c[i];
    rep(i, m) {
        if (n <= a) {
            n += b;
        }
        n -= c[i];
        if (n < 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "complete" << endl;
}