#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A.at(i);
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    int alice = 0, bob = 0;
    for(int i = 0; i < n; i += 2) alice += A.at(i);
    for(int i = 1; i < n; i += 2) bob += A.at(i);

    cout << alice - bob << endl;
}
