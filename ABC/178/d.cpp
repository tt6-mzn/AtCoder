#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    long long s;
    cin >> s;
    if(s <= 2) {
        cout << 0 << endl;
        return 0;
    }
    else if(s <= 5) {
        cout << 1 << endl;
        return 0;
    }
    vector<long long> a(s + 1);
    a.at(1) = 0;
    a.at(2) = 0;
    for(int i = 3; i <= 5; i++) a.at(i) = 1;
    for(int i = 6; i <= s; i++) {
        a.at(i) = (a.at(i - 1) + a.at(i - 3)) % 1000000007;
    }
    cout << a.at(s) << endl;
}