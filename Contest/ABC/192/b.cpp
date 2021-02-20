#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    string alp = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < s.size(); i += 2) {
        bool flg = false;
        for (char c : alp) {
            if (s[i] == c) {
                flg = true;
            }
        }
        if (flg == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    string Alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 1; i < s.size(); i += 2) {
        bool flg = false;
        for (char c : Alp) {
            if (s[i] == c) {
                flg = true;
            }
        }
        if (flg == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
