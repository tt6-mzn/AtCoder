#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<string> a;
vector<vector<bool>> seen;
int h, w;

bool check() {
    rep(i, h) {
        rep(j, w) {
            if (a[i][j] == '#' && seen[i][j] == false) {
                return false;
            }
        }
    }
    return true;
}

bool dfs(int i, int j) {
    seen[i][j] = true;
    if (i == h - 1 && j == w - 1) {
        if (check()) {
            seen[i][j] = false;
            return true;
        }
        else {
            seen[i][j] = false;
            return false;
        }
    }
    if (i + 1 < h && a[i + 1][j] == '#') {
        if (dfs(i + 1, j)) {
            seen[i][j] = false;
            return true;
        }
    }
    if (j + 1 < w && a[i][j + 1] == '#') {
        if (dfs(i, j + 1)) {
            seen[i][j] = false;
            return true;
        }
    }
    seen[i][j] = false;
    return false;
}

int main() {
    cin >> h >> w;
    rep(i, h) {
        string t;
        cin >> t;
        a.push_back(t);
    }
    seen.resize(h, vector<bool>(w));

    if (dfs(0, 0)) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}
