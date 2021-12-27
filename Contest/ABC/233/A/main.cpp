#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x, y;
    cin >> x >> y;
    cout << (max(0, y - x) + 10 - 1) / 10 << endl;
    return 0;
}