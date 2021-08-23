#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    if(s.size() <= k) {
        cout << s << endl;
    }
    else {
        rep(i, k) {
            cout << s.at(i);
        }
        cout << "..." << endl;
    }
}