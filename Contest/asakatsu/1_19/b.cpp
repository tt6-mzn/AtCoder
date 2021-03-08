#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int i = 0, j = 0, k = 0;
    while (i < s.size() && s[i] != 'i' && s[i] != 'I') i++;
    if (i == s.size()) {
        cout << "NO" << endl;
        return 0;
    }
    j = i + 1;
    while (j < s.size() && s[j] != 'c' && s[j] != 'C') j++;
    if (j == s.size()) {
        cout << "NO" << endl;
        return 0;
    }
    k = j + 1;
    while (k < s.size() && s[k] != 't' && s[k] != 'T') k++;
    if (k == s.size()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}