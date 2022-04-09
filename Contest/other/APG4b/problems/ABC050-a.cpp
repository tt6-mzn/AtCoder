#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int a, b;
    char op;
    cin >> a >> op >> b;
    if(op == '+') {
        cout << a + b << endl;
    }
    else {
        cout << a - b << endl;
    }
}
