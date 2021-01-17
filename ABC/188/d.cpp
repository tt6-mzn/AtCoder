#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, C;
    cin >> n >> C;
    map<int, long long> events;
    rep(i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        events[a] += c;
        events[b + 1] -= c;
    }
    long long ans = 0;
    long long s = 0;
    int pre = 0;
    for (auto event : events) {
        ans += min((long long)C, s) * (event.first - pre);
        s += event.second;
        pre = event.first;
    }
    cout << ans << endl;
    return 0;
}