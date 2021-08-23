#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string n;
    cin >> n;
    int ans = 0;
    rep(i, n.size()) {
        ans += n.at(i) - '0';
    }
    if(ans % 9 == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}