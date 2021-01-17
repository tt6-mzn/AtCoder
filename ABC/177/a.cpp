#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int d, t, s;
    cin >> d >> t >> s;
    if(d <= t * s) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}