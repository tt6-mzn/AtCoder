#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n;
    d = n % 10;
    c = (n % 100 - d) / 10;
    b = (n % 1000 - c*10 - d) / 100;
    a = (n - b*100 - c*10 - d) / 1000;
    if(a == b && b == c || b == c && c == d) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
