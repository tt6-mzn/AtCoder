#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void fill_isl(vector<string> &isl, int i, int j) {
    isl[i][j] = 'x';
    if (0 <= i - 1 && isl[i - 1][j] == 'o') {
        fill_isl(isl, i - 1, j);
    }
    if (0 <= j - 1 && isl[i][j - 1] == 'o') {
        fill_isl(isl, i, j - 1);
    }
    if (i + 1 < 10 && isl[i + 1][j] == 'o') {
        fill_isl(isl, i + 1, j);
    }
    if (j + 1 < 10 && isl[i][j + 1] == 'o') {
        fill_isl(isl, i, j + 1);
    }
}

bool judge(vector<string> isl) {
    rep(i, 10) {
        rep(j, 10) {
            if (isl[i][j] == 'o') {
                fill_isl(isl, i, j);
                rep(i, 10) {
                    rep(j, 10) {
                        if (isl[i][j] == 'o') {
                            return false;
                        }
                    }
                }
                return true;
            }
        }
    }
}

int main() {
    vector<string> isl(10);
    rep(i, 10) cin >> isl[i];
    rep(i, 10) {
        rep(j, 10) {
            if (isl[i][j] == 'x') {
                isl[i][j] = 'o';
                if (judge(isl)) {
                    cout << "YES" << endl;
                    return 0;
                }
                isl[i][j] = 'x';
            }
        }
    }
    cout << "NO" << endl;
}
