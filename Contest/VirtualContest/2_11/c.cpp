#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string n;
    cin >> n;
    reverse(n.begin(), n.end());
    int odd = 0, eve = 0;
    for (int i = 0; i < n.size(); i += 2) {
        odd += n[i] - '0';
    }
    for (int i = 1; i < n.size(); i += 2) {
        eve += n[i] - '0';
    }
    cout << eve << " " << odd << endl;
}