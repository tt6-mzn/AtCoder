#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    rep(i,  n) {
        cin >> d.at(i).first >> d.at(i).second;
    }

    int cnt = 0;
    bool flg = false;
    rep(i, n) {
        if(d.at(i).first == d.at(i).second) {
            cnt++;
        }
        else {
            cnt = 0;
        }
        if(cnt == 3) {
            flg = true;
        }
    }

    if(flg) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}