#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> P(n);

    rep(i, n) {
        int a, b;
        cin >> a >> b;
        P.at(i) = make_pair(b, a);
    }

    sort(P.begin(), P.end());

    rep(i, n) {
        cout << P.at(i).second << " " << P.at(i).first << endl;
    }
}
