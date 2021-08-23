#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    string h = "24579";
    string p = "0168";
    string n;
    cin >> n;
    rep(i, h.size()) {
        if(n.at(n.size() - 1) == h.at(i)) {
            cout << "hon" << endl;
            return 0;
        }
    }
    rep(i, p.size()) {
        if(n.at(n.size() - 1) == p.at(i)) {
            cout << "pon" << endl;
            return 0;
        }
    }
    cout << "bon" << endl;
}