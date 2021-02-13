#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<string>> table(h, vector<string>(w));
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    rep(i, h) {
        rep(j, w) {
            cin >> table[i][j];
        }
    }
    rep(i, w) {
        rep(j, h) {
            if (table[j][i] == "snuke") {
                cout << alp[i] + to_string(j + 1) << endl;
                return 0;
            }
        }
    }
}