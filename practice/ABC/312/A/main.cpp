#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    set<string> st = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    if (st.count(s) == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}