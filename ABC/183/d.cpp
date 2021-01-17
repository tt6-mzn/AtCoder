#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, w, len = 200100;
    cin >> n >> w;
    vector<long long> imos(len, 0);
    vector<long long> sum_imos(len, 0);
    rep(i, n) {
        long long s, t, p;
        cin >> s >> t >> p;
        imos.at(s) += p;
        imos.at(t) -= p;
    }
    sum_imos.at(0) = imos.at(0);
    for(int i = 1; i < len; i++) {
        sum_imos.at(i) = imos.at(i) + sum_imos.at(i - 1);
    }
    bool flg = true;
    rep(i, len) {
        if(sum_imos.at(i) > w) {
            flg = false;
        }
    }
    if(flg) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}