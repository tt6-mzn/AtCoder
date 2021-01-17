#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> A(n), P(n);
    for(int i = 0; i < n; i++) {
        cin >> A.at(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> P.at(i);
    }

    int ans = 0;
    for(int a : A) {
        for(int p : P) {
            if(a + p == s) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
