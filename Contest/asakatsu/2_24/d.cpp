#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ai;
    ai = a[a.size() - 1];
    int m = (ai + 1) / 2;
    int j = distance(a.begin(), lower_bound(a.begin(), a.end(), m));
    if (ai == a[j]) {
        cout << ai << " " << a[j - 1] << endl;
        return 0;
    }
    if (ai - a[j] < ai - a[j - 1]) {
        cout << ai << " " << a[j] << endl;
    }
    else {
        cout << ai << " " << a[j - 1] << endl;
    }
}
