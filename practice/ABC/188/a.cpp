#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n) i++)

int main() {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    if (x + 3 > y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}