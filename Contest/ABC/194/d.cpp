#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    double ans = 0.0;
    for (int i = 1; i < n; i++) {
        ans += 1.0 / (double)i;
    }
    ans *= n;
    printf("%.10lf\n", ans);
}