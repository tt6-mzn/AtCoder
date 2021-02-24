#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int bb = 0;
    int aa = 0;
    for (char c : s) {
        if (c == 'c') {
            cout << "No" << endl;
        }
        else if (c == 'a') {
            if (aa < a + b) {
                cout << "Yes" << endl;
                aa++;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            if (aa < a + b && bb < b) {
                cout << "Yes" << endl;
                aa++;
                bb++;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}