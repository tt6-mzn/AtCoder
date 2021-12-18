#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k, a;
    cin >> n >> k >> a;
    rep(i, k - 1) {
        if (a == n) a = 1;
        else a++;
    }
    cout << a << endl;
}