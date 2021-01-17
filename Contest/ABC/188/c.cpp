#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    queue<long long> que;
    vector<long long> a(pow(2, n));
    long long t, s;
    rep(i, pow(2, n)) {
        cin >> t;
        a.at(i) = t;
        que.push(t);
    }

    while (que.size() > 2) {
        for (int i = 0; i < que.size() / 2; i++) {
            s = que.front();
            que.pop();
            t = que.front();
            que.pop();
            que.push(max(s, t));
        }
    }
    s = que.front();
    que.pop();
    t = que.front();
    que.pop();
    s = min(s, t);
    rep(i, pow(2, n)) {
        if (s == a.at(i)) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}