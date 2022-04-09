#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (b * c * 2) + (b * a * 2) + (a * c * 2) << endl;
}