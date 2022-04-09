#include <bits/stdc++.h>
using namespace std;

int main() {
    int type, p, n;
    string text;
    cin >> type;
    if(type == 1) {
        cin >> p >> n;
        cout << n * p << endl;
    }
    else {
        cin >> text >> p >> n;
        cout << text << "!" << endl;
        cout << n * p << endl;
    }
}
