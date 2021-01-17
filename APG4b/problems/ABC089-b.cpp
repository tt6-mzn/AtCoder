#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    string s;
    cin >> n;
    rep(i, n) {
        cin >> s;
        if(s == "Y") {
            cout << "Four" << endl;
            break;
        }
        else if(i == n - 1) {
            cout << "Three" << endl;
        }
    }
}
