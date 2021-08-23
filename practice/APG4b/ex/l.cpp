#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, i;
    string op;
    cin >> n >> a;
    for(i = 0; i < n; i++) {
        cin >> op >> b;
        if(op == "+") {
            cout << i + 1 << ":" << a + b << endl;
            a = a + b;
        }
        else if(op == "-") {
            cout << i + 1 << ":" << a - b << endl;
            a = a - b;
        }
        else if(op == "*") {
            cout << i + 1 << ":" << a * b << endl;
            a = a * b;
        }
        else if(op == "/" && b != 0) {
            cout << i + 1 << ":" << a / b << endl;
            a = a / b;
        }
        else {
            cout << "error" << endl;
            break;
        }
    }
}
