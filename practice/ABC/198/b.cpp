#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string n;
    cin >> n;
    int i = n.size() - 1;
    while (i > 0 && n[i] == '0') i--;
    string rev_n = n.substr(0, i + 1);
    reverse(rev_n.begin(), rev_n.end());
    if (rev_n == n.substr(0, i + 1)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}