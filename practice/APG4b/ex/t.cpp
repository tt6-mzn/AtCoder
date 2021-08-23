#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> ans(n, vector<char>(n, '-'));

    int a, b;
    rep(i, m) {
        cin >> a >> b;
        ans.at(a - 1).at(b - 1) = 'o';
        ans.at(b - 1).at(a - 1) = 'x';
    }

    rep(i, n) {
        rep(j, n) {
            cout << ans.at(i).at(j);
            if(j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
