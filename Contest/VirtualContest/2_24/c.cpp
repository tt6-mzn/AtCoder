#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dfs(int i, string s) {
    if (i == 0) {
        cout << s << endl;
        return;
    }
    dfs(i - 1, s + "a");
    dfs(i - 1, s + "b");
    dfs(i - 1, s + "c");
}

int main() {
    int n;
    cin >> n;
    dfs(n, "");
}