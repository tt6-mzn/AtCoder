#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    rep(i, n) cin >> xy[i].first >> xy[i].second; 
    map<pair<int, int>, int> mp;
    rep(i, n) mp[xy[i]]++;
    int ans = 0;
    rep(j, n) {
        rep(i, j) {
            if (xy[i].first == xy[j].first || xy[i].second == xy[j].second) continue;
            pair<int, int> left = make_pair(xy[i].first, xy[j].second);
            pair<int, int> right = make_pair(xy[j].first, xy[i].second);
            if (mp[left] > 0 && mp[right] > 0) ans++;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}