
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) {
        cin >> A.at(i);
    }

    int avg = 0;
    rep(i, n) {
        avg += A.at(i);
    }
    avg /= n;

    rep(i, n) {
        if(A.at(i) - avg > 0) {
            cout << A.at(i) - avg << endl;
        }
        else {
            cout << (-1) * (A.at(i) - avg) << endl;
        }
    }
}
