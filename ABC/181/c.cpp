#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    rep(i, n) cin >> xy.at(i).first >> xy.at(i).second;
    pair<int, int> v1, v2;
    bool flg = false;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                v1.first = xy.at(j).first - xy.at(i).first;
                v1.second = xy.at(j).second - xy.at(i).second;
                v2.first = xy.at(k).first - xy.at(i).first;
                v2.second = xy.at(k).second - xy.at(i).second;
                if(v1.first == 0 || v2.first == 0) {
                    if(v1.first == v2.first) {
                        flg = true;
                    }
                }
                else {
                    if(v1.second*v2.first == v1.first*v2.second) {
                        flg = true;
                    }
                }
            }
        }
    }
    if(flg) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}