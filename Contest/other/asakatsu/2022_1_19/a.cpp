#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> p(n, vector<int>(d));
    rep(i, n) {
        rep(j, d) {
            cin >> p[i][j];
        }
    }

    int ans = 0;
    for (int  i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = 0;
            rep(k, d) {
                dist += (p[i][k] - p[j][k]) * (p[i][k] - p[j][k]);
            }
            int k = 0;
            while (k * k <= dist) {
                k++;
            }
            k--;
            if (k * k == dist) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}