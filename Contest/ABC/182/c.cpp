#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string n;
    cin >> n;
    int bit_max = 1;
    rep(i, n.size()) bit_max *= 2;
    int sum, cnt, ans = -1;

    for(int bit = 1; bit < bit_max; bit++) {
        sum = 0;
        cnt = 0;
        rep(i, n.size()) {
            if(bit >> i & 1) {
                sum += n.at(i) - '0';
                cnt++;
            }
        }
        if(sum % 3 == 0) {
            ans = max(cnt, ans);
        }
    }
    if(ans != -1) {
        cout << n.size() - ans << endl;
    }
    else {
        cout << -1 << endl;
    }
}