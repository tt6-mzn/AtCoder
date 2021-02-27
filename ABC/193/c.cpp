#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    if (n <= 3) {
        cout << n << endl;
        return 0;
    }
    long long a = 2;
    long long cnt = 0;
    vector<bool> seen(1100100100, false);
    while (a * a <= n) {
        if (seen.at(a) == false) {
            long long x = a;
            while (x * a <= n) {
                x *= a;
                if (x < 1100100100) seen.at(x) = true;
                cnt++;
            }
        }
        a++;
    }
    cout << n - cnt << endl;
}