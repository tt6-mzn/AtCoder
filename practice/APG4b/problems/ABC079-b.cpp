#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)

int main() {
    int n;
    cin >> n;
    vector<long long int> L(n + 1);

    L[0] = 2;
    L[1] = 1;
    for(int i = 2; i < n + 1; i++) {
        L[i] = L[i - 1] + L[i - 2];
    }

    cout << L[n] << endl;
}
