#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string t = "oxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxx";
    string s;
    cin >> s;
    if (t.find(s) != string::npos) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}