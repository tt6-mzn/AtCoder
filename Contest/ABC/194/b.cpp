#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    int ans = 1100100100;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                ans = min(ans, a[i] + b[j]);
            }
            else {
                ans = min(ans, max(a[i], b[j]));
            }
        }
    }
    cout << ans << endl;
}
