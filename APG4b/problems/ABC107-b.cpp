#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> grid.at(i).at(j);
        }
    }

    bool flg;
    rep(i, h) {
        flg = true;
        rep(j, w) {
            if(grid.at(i).at(j) == '#') {
                flg = false;
            }
        }
        if(flg) {
            rep(j, w) {
                grid.at(i).at(j) = 'o';
            }
        }
    }
    rep(j, w) {
        flg = true;
        rep(i, h) {
            if(grid.at(i).at(j) == '#') {
                flg = false;
            }
        }
        if(flg) {
            rep(i, h) {
                grid.at(i).at(j) = 'o';
            }
        }
    }

    rep(i, h) {
        int cnt = 0;
        rep(j, w) {
            if(grid.at(i).at(j) != 'o') {
                cout << grid.at(i).at(j);
            }
            else {
                cnt++;
            }
        }
        if(cnt < w) {
            cout << endl;
        }
    }
}
