#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, w;
    cin >> a >> b >> w;
    w = w * 1000;
    int n = 1;
    while (!(a * n <= w && w <= b * n)) {
        n++;
        if (n > 1000000) {
            cout << "UNSATISFIABLE" << endl;
            return 0;
        }
    }
    cout << n << " ";
    while (a * n <= w && w <= b * n) n++;
    cout << n - 1 << endl;
}
