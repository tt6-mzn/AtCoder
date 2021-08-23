#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    string s;
    int ans = 1;
    cin >> s;
    for(int i = 1; i < s.size(); i += 2) {
        if(s.at(i) == '+') {
            ans++;
        }
        else {
            ans--;
        }
    }
    cout << ans << endl;
}
