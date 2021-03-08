#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int max_ta = -1000000000;
    rep(i, n) { // takahashi
        int max_ao = -1000000000, max_j;
        rep(j, n) { // aoki
            if (i != j) {
                int ao = 0;
                for (int k = min(i, j) + 1; k <= max(i, j); k += 2) {
                    ao += a[k];
                }
                if (ao > max_ao) {
                    max_ao = ao;
                    max_j = j;
                }
            }
        }
        int ta = 0;
        for (int k = min(i, max_j); k <= max(i, max_j); k += 2) {
            ta += a[k];
        }
        max_ta = max(ta, max_ta);
    }
    cout << max_ta << endl;
}