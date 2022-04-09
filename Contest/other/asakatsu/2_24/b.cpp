#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool comp(string a, string b) {
    rep(i, min(a.size(), b.size())) {
        if (a[i] != b[i]) {
            return a < b;
        }
    }
    return a.size() < b.size();
}

int main() {
    vector<string> a;
    for (int i = 1; i <= 1000; i++) {
        a.push_back(to_string(i));
    }
    sort(a.begin(), a.end(), comp);
    rep(i, 1000) {
        cout << a[i] << endl;
    }
}