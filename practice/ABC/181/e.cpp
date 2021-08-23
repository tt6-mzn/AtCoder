#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int nibutan(vector<long long> &a, int b) {
    int l = -1, r = a.size();
    while(r - l > 1) {
        if(b <= a.at((l + r) / 2)) {
            r = (l + r) / 2;
        }
        else {
            l = (l + r) / 2;
        }
    }
    return r;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    vector<long long> w(m);
    rep(i, n) cin >> h.at(i);
    rep(i, m) cin >> w.at(i);
    sort(h.begin(), h.end());
    vector<long long> d1(n / 2);
    vector<long long> d2(n / 2);
    for(int i = 0; i < n / 2; i++) {
        d1.at(i) = abs(h.at(2 * i) - h.at(2 * i + 1));
    }
    for(int i = 0; i < n / 2; i++) {
        d2.at(i) = abs(h.at(2 * i + 1) - h.at(2 * i + 2));
    }
    vector<long long> sum_d1((n + 1) / 2);
    vector<long long> sum_d2((n + 1) / 2);
    sum_d1.at(0) = 0;
    rep(i, n / 2) {
        sum_d1.at(i + 1) = d1.at(i) + sum_d1.at(i);
    }
    
}