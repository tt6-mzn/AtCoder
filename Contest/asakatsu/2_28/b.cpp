#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int i = 1;
    while (a[0] == a[i]) i++;   
    cout << a[i] << endl;
}