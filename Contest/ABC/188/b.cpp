#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    rep(i, n) {
        cin >> b.at(i);
    }
    long long dot = 0;
    rep(i, n) {
        dot += a.at(i) * b.at(i);
    }
    if (dot == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}