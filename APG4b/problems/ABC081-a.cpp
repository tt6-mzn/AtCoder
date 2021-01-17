#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, a, b, c;
    cin >> s;
    a = s % 10;
    b = (s % 100 - a) / 10;
    c = (s - 10*b - a) / 100;
    cout << a + b + c << endl;
}
