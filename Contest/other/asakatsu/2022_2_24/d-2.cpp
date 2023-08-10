#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ai;
    ai = a[a.size() - 1];
    int m = (ai + 1) / 2;
    int j;
    int d = 1100100100;
    rep(k, n) {
        if (a[k] != ai) {
            if (d > abs(m - a[k])) {
                d = abs(m - a[k]);
                j = k;
            }
        }
    }
    cout << ai << " " << a[j] << endl;
}

