#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    int s = l1 + l2 + l3;
    int t = l1 - l2 - l3;
    int u = l3 - l1 - l2;
    if (l1 <= l2 + l3) {
        printf("%.10lf\n", (double)(s * s) * 3.141592653589);
    }
    else if (l3 > l1 + l2) {

    }
    else {
        double ans;
        ans = (double)((s * s) - (t * t)) * 3.141592653589;
        printf("%.10lf\n", ans);
    }
}
