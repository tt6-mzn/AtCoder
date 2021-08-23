#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    auto dist = [&](int i, int j) {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        return sqrt(dx * dx + dy * dy);
    };
    double len = 0;
    rep(i, n)rep(j, i) {
        len += dist(i, j);
    }
    int num = 2;
    for (int i = n - 1; i >= 1; i--) num *= i;
    int fact = 1;
    for (int i = n; i >= 1; i--) fact *= i;
    double ans = (len * num) / fact;
    printf("%.10f\n", ans);
    return 0;
}