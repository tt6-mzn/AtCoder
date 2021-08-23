#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    map<int, int> m;
    rep(i, n) {
        if (m.count(a.at(i))) {
            m[a.at(i)] += 1;
        }
        else {
            m[a.at(i)] = 1;
        }
    }

    int k, v = -1;
    rep(i, n) {
        if (m[a.at(i)] > v) {
            k = a.at(i);
            v = m[a.at(i)];
        }
    }

    cout << k << " " << v << endl;
}