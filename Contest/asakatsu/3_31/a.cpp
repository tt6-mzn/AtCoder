#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int a;
    cin >> a;
    if (a >= n % 500) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}