#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long N, C;
    cin >> N >> C;
    vector<pair<long long, long long>> t(2 * N);
    long long a, b, c;
    rep(i, N) {
        cin >> a >> b >> c;
        t.at(2 * i).first = a;
        t.at(2 * i + 1).first = b + 1;
        t.at(2 * i).second = c;
        t.at(2 * i + 1).second = (-1) * c;
    }
    sort(t.begin(), t.end());

    long long i = 0;
    c = t.at(0).second;
    long long ans = 0;
    while (i < 2 * N - 1) {
        while (i < 2 * N - 1 && t.at(i).first == t.at(i + 1).first) {
            i++;
            c += t.at(i).second;
        }
        if (i < 2 * N - 1) {
            ans += (t.at(i + 1).first - t.at(i).first) * min(c, C);
        }
        i++;
        if (i < 2 * N - 1)
            c += t.at(i).second;
    }
    cout << ans << endl;
}