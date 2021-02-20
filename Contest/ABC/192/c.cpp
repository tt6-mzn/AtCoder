#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long f(long long n) {
    string s = to_string(n);
    vector<long long> g1, g2;
    for (char c : s) {
        g1.push_back(c - '0');
        g2.push_back(c - '0');
    }
    sort(g1.begin(), g1.end(), greater<long long>());
    sort(g2.begin(), g2.end());
    string g1_s = "", g2_s = "";
    for (int i = 0; i < g1.size(); i++) {
        g1_s += to_string(g1[i]);
        g2_s += to_string(g2[i]);
    }
    return (long long)(atoi(g1_s.c_str()) - atoi(g2_s.c_str()));
}

int main() {
    long long n, k;
    cin >> n >> k;
    rep(i, k) {
        n = f(n);
    }
    cout << n << endl;
}

