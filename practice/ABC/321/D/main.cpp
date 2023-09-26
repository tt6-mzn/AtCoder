#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m;
  long long p;
  cin >> n >> m >> p;
  vector<long long> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  sort(b.begin(), b.end());

  vector<long long> b_acc(m + 1, 0);
  for (int i = 1; i <= m; i++)
    b_acc[i] = b_acc[i - 1] + b[i - 1];

  //   rep(_, b_acc.size()) { cout << b_acc[_] << " "; }
  //   cout << endl;

  long long ans = 0;

  for (auto ai : a) {
    if (ai >= p) {
      ans += p * m;
      continue;
    }
    auto it = upper_bound(b.begin(), b.end(), p - ai);
    auto index = distance(b.begin(), it);
    ans += b_acc[index] + ai * index;
    // cout << index << " " << ans << endl;
    ans += p * (m - index);
    // cout << index << " " << ans << endl;
  }

  cout << ans << endl;

  return 0;
}