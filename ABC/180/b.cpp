#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x.at(i);

    long ans1 = 0;
    for(int i = 0; i < n; i++) ans1 += abs(x.at(i));
    cout << ans1 << endl;

    long ans2 = 0;
    for(int i = 0; i < n;i ++) ans2 += (long)x.at(i) * x.at(i);
    cout << sqrt(ans2) << endl;

    int ans3 = 0;
    for(int i = 0; i < n; i++) ans3 = max(ans3, abs(x.at(i)));
    cout << ans3 << endl;
}