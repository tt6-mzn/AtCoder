#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string x;
    cin >> x;
    long long n = x.size();
    vector<long long> keta(n, 0);
    rep(i, n) keta[i] = x[i] - '0';
    vector<long long> keta_s(n);
    keta_s[0] = keta[0];
    for (int i = 1; i < n; i++) keta_s[i] = keta_s[i - 1] + keta[i];

    long long amari = 0;
    for (int i = n - 1; i >= 0; i--) {
        long long tmp = keta_s[i] + amari;
        keta_s[i] = tmp % 10;
        amari = tmp / 10;
    }
    bool flg = true;
    if (amari != 0) {
        cout << amari;
        flg = false;
    }
    int i = 0;
    while (keta_s[i] == 0 && flg) i++;
    for (; i < keta_s.size(); i++) cout << keta_s[i];
    cout << endl;

    return 0;
}