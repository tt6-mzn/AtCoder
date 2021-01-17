#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s.at(i);
    map<string, int> memo;
    rep(i, n) {
        if(s.at(i).at(0) == '!') {
            memo[s.at(i)] = 1;
        }
    }
    rep(i, n) {
        if(s.at(i).at(0) != '!' && memo["!" + s.at(i)] == 1) {
            cout << s.at(i) << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}