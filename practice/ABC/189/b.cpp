#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, x;
    cin >> n >> x;
    int al = 0;
    rep(i, n) {
        int v, p;
        cin >> v >> p;
        al += v * p;
        if (al > 100 * x) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}