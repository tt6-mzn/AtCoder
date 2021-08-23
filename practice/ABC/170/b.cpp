#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x, y;
    cin >> x >> y;
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            if(i + j == x && 2 * i + 4 * j == y) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}