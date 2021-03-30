#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    double va, vb, l;
    cin >> va >> vb >> l;
    double t;
    rep(i, n) {
        t = l / va;
        l = vb * t;
    }
    printf("%.10lf\n", l);
}