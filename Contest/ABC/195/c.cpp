#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    long long ten3 = 1000LL;
    long long ten6 = 1000000LL;
    long long ten9 = 1000000000LL;
    long long ten12 = 1000000000000LL;
    long long ten15 = 1000000000000000LL;
    if (n < ten3) {
        cout << 0 << endl;
    }
    else if (ten3 <= n && n < ten6) {
        cout << n - ten3 + 1 << endl;
    }
    else if (ten6 <= n && n < ten9) {
        cout << (ten6 - ten3) + 2 * (n - ten6 + 1) << endl;
    }
    else if (ten9 <= n && n < ten12) {
        cout << (ten6 - ten3) + 2 * (ten9 - ten6) + 3 * (n - ten9 + 1) << endl;
    }
    else if (ten12 <= n && n < ten15) {
        cout << (ten6 - ten3) + 2 * (ten9 - ten6) + 3 * (ten12 - ten9) + 4 * (n - ten12 + 1) << endl; 
    }
    else {
        cout << (ten6 - ten3) + 2 * (ten9 - ten6) + 3 * (ten12 - ten9) + 4 * (ten15 - ten12) + 5 << endl;
    }
}

