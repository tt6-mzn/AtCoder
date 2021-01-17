#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> town(n + 1, 0);

    rep(i, m) {
        cin >> a >> b;
        if(a == b) town.at(a)++;
        else {
            town.at(a)++;
            town.at(b)++;
        }
    }
    rep(i, n) {
        cout << town.at(i + 1) << endl;
    }
}
