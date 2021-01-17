#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long N, T, t = 0, n, m;
    cin >> N >> m >> T;
    n = N;
    vector<pair<long long, long long>> ab(m);
    rep(i, m) {
        cin >> ab.at(i).first >> ab.at(i).second;
    }
    rep(i, m) {
        n -= ((ab.at(i).first) - t);
        if(n <= 0) {
            cout << "No" << endl;
            return 0;
        }
        n = min(N, n + (ab.at(i).second - ab.at(i).first));
        t = ab.at(i).second;
    }
    n -= (T - ab.at(m - 1).second);
    if(n <= 0) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}