#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, n) {
        cin >> p.at(i).first >> p.at(i).second;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int dx, dy;
            dx = abs(p.at(i).first - p.at(j).first);
            dy = abs(p.at(i).second - p.at(j).second);
            if(dx >= dy) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}