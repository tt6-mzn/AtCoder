#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long a, b, c, d;
    long long a1, a2, a3, a4;
    cin >> a >> b >> c >> d;
    
    a1 = a * c;
    a2 = a * d;
    a3 = b * c;
    a4 = b * d;

    cout << max({a1, a2, a3, a4}) << endl;
}