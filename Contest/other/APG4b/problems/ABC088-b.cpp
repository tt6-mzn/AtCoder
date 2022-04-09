#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A.at(i);

    int alice = 0, bob = 0;
    int max, max_index;
    rep(i, n + 1 / 2) {
        max = 0;
        rep(i, n) {
            if(A.at(i) > max) {
                max = A.at(i);
                max_index = i;
            }
        }
        alice += max;
        A.at(max_index) = 0;

        max = 0;
        rep(i, n) {
            if(A.at(i) > max) {
                max = A.at(i);
                max_index = i;
            }
        }
        bob += max;
        A.at(max_index) = 0;
    }
    cout << alice - bob << endl;
}
