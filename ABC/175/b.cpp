#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i, n) cin >> L.at(i);
    sort(L.begin(), L.end());
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(L.at(i) + L.at(j) > L.at(k)) {
                    if(L.at(i)!=L.at(j)&&L.at(i)!=L.at(k)&&L.at(j)!=L.at(k)) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}