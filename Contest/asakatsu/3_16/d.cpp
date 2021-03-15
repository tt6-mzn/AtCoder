#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string c = "ABXY";
    vector<string> sbs;
    rep(i, 4) {
        rep(j, 4) {
            sbs.push_back(c.substr(i, 1) + c.substr(j, 1));
        }
    }
    int ans = 1001001001;
    rep(i, sbs.size()) {
        rep(j, i) {
            int t = 0;
            int k = 0;
            while (k < s.size() - 1) {
                if (s.substr(k, 2) == sbs[i] || s.substr(k, 2) == sbs[j]) {
                    t++;
                    k += 2;
                }
                else {
                    k++;
                }
            }
            ans = min(ans, (int)s.size() - t);
        }
    }
    cout << ans << endl;
}