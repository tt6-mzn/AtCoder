#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    double ans = 0.0;
    for (int i = 1; i <= n; i++) {
        if (i >= k) {
            ans += 1.0 / (double)n;
        }
        else {
            int cnt = 0;
            int j = i;
            while (j < k) {
                j *= 2;
                cnt++;
            }
            ans += 1.0 / (double)(n) * (1.0 / (double)(1 << cnt));
        }
    }
    printf("%.10f\n", ans);
}