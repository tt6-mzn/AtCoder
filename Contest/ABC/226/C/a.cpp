#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<long long> t(n);
    vector<vector<int>> a(n);
    rep(i, n) {
        int k;
        cin >> t[i] >> k;
        rep(j, k) {
            int tmp;
            cin >> tmp;
            tmp--;
            a[i].push_back(tmp);
        }
    }
    vector<bool> todo(n, false);
    queue<int> que;
    que.push(n - 1);
    while (!que.empty()) {
        int i = que.front(); que.pop();
        todo[i] = true;
        for (int next : a[i]) {
            if (todo[next] == false) que.push(next);
        }
    }
    long long ans = 0;
    rep(i, n) {
        if (todo[i]) {
            ans += t[i];
        }
    }
    cout << ans << endl;
}

