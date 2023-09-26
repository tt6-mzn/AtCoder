#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int k;
int cnt = 0;

void dfs(int now, int d, string s) {
  if (now == d) {
    cnt++;
    if (cnt == k) {
      cout << s << endl;
      return;
    }
  }
  if (now == 0) {
    for (int i = 1; i <= 9; i++) {
      dfs(now + 1, d, s + (char)('0' + i));
    }
  } else {
    if (s[now - 1] == '0')
      return;
    int i = 0;
    while (s[now - 1] > (char)('0' + i)) {
      dfs(now + 1, d, s + (char)('0' + i));
      i++;
    }
  }
}

int main() {
  cin >> k;
  for (int i = 1; i <= 10; i++) {
    dfs(0, i, "");
  }
  return 0;
}