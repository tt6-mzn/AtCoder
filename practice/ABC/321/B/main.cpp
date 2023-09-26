#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n - 1);
  rep(i, n - 1) cin >> a[i];

  rep(ans, 101) {
    a.push_back(ans);

    int s = accumulate(a.begin(), a.end(), 0);
    int min_a = *min_element(a.begin(), a.end());
    int max_a = *max_element(a.begin(), a.end());

    if (s - min_a - max_a >= x) {
      cout << ans << endl;
      return 0;
    }

    a.pop_back();
  }

  cout << -1 << endl;
  return 0;
}