#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> memo(n + 5, 0);
    int mex = 0;
    for (int i = 0; i < m; i++) {
        memo[a[i]]++;
        if (a[i] == mex + 1) {
            while (memo[mex] > 0) mex++;
        }
    }
    int ans = mex;
    for (int i = 1; i < m; i++) {
        memo[a[i - 1]]--;
        memo[a[i + m - 1]]++;
        if (memo[a[i - 1]] == 0 && a[i - 1] <= mex) {
            mex = a[i - 1];
        }
        if (a[i + m - 1] == mex + 1) {
            while (memo[mex] > 0) mex++;
        }
        ans = min(ans, mex);
    }
    cout << ans << endl;
}
