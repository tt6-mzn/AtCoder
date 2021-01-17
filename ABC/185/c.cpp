#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    long long l;
    cin >> l;
    long long ans = 1;
    vector<bool> memo(12, true);

    for(int i = l - 11; i < l; i++) {
        ans *= i;
        for(int j = 2; j < 12; j++) {
            if(memo.at(j) && ans % j == 0) {
                memo.at(j) = false;
                ans /= j;
            }
        }
    }
    cout << ans << endl;
}