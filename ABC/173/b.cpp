#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int ac = 0, wa = 0, tle = 0, re = 0;
    rep(i, n) {
        string s;
        cin >> s;
        if(s == "AC") {
            ac++;
        }
        else if(s == "WA") {
            wa++;
        }
        else if(s == "TLE") {
            tle++;
        }
        else {
            re++;
        }
    }
    cout << "AC x " << ac << endl;
    cout << "WA x " << wa << endl;
    cout << "TLE x " << tle << endl;
    cout << "RE x " << re << endl;
}