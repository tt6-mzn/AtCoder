#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string w;
    cin >> w;
    vector<int> counter(26, 0);
    for (auto c : w) {
        counter[c - 'a']++;
    }
    bool flg = true;
    for (auto i : counter) {
        if (i % 2 != 0) {
            flg = false;
        }
    }
    if (flg) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}