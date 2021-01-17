#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long a;
    string b;
    cin >> a >> b;
    int bx100;
    bx100 = (b.at(0) - '0') * 100 + (b.at(2) - '0') * 10 + (b.at(3) - '0');
    cout << bx100 << endl;
    cout << (a * bx100) / 100 << endl;
}