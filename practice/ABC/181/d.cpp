#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    string s, t;
    cin >> s;
    bool flg = false;
    vector<int> memo1(10), memo2(10);
    rep(i, 10) memo1.at(i) = 0;
    rep(i, s.size()) memo1.at(s.at(i) - '0')++;
    
    if(s.size() == 1) {
        if(s == "8") {
            flg = true;
        }
    }
    else if(s.size() == 2) {
        if(stoi(s) % 8 == 0) {
            flg = true;
        }
        swap(s.at(0), s.at(1));
        if(stoi(s) % 8 == 0) {
            flg = true;
        }
    }
    else {
        for(int i = 111; !flg && i < 1000; i++) {
            if(i % 8 == 0) {
                t = to_string(i);
                rep(j, 10) memo2.at(j) = 0;
                rep(j, t.size()) memo2.at(t.at(j) - '0')++;
                flg = true;
                rep(j, 10) {
                    if (memo1.at(j) < memo2.at(j)) {
                        flg = false;
                    }
                }
            }
        }
    }
    
    if(flg) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}