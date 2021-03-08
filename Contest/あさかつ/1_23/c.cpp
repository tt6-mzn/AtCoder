#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    deque<int> que;
    rep(i, n) {
        if (i % 2 == 0) {
            que.push_back(a[i]);
        }
        else {
            que.push_front(a[i]);
        }
    }
    if (n % 2 == 0) {
        rep(i, n) {
            cout << que[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    else {
        for (int i = n - 1; i >= 0; i--) {
            cout << que[i];
            if (i > 0) {
                cout << " ";
            }
        }
        cout << endl;
    }
}