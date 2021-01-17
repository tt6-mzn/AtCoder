#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    char a;
    cin >> a;
    string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alp = "abcdefghijklmnopqrstuvwxyz";
    rep(i, ALP.size()) {
        if(a == ALP.at(i)) {
            cout << "A" << endl;
            return 0;
        }
        else if(a == alp.at(i)) {
            cout << "a" << endl;
            return 0;
        }
    }
}