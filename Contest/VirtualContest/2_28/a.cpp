#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int p, q, r;
    cin >> p >> q >> r;
    cout << (p + q + r) - max(max(p, q), r) << endl;
}