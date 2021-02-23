#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string c = "ABXY";
    int m1 = -1, m2 = -1;
    string m1_s, m2_s;
    rep(i, 4) {
        rep(j, 4) {
            int cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < s.size() - 1; k++) {
                string sub = s.substr(k, 2);
                if (sub[0] == c[i] && sub[1] == c[j]) cnt1++;
                cout << cnt1 << endl;
            } 
        }
    }
}

