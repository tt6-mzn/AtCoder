#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    rep(i, h) {
        cin >> A.at(i);
    }

    rep(i, w + 2) {
        cout << "#";
    }
    cout << endl;
    rep(i, h) {
        cout << "#" << A.at(i) << "#" << endl;
    }
    rep(i, w + 2) {
        cout << "#";
    }
    cout << endl;
}
