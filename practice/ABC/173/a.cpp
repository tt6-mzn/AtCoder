#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    if(n % 1000 == 0) cout << 0 << endl; 
    else cout << 1000 - (n % 1000) << endl;
}