#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string c;
    cin >> c;
    int i = 0, j = n - 1;
    int ans = 0;
    while(i < j) {
        while(i < n && c.at(i) == 'R') i++;
        while(0 <= j && c.at(j) == 'W') j--;
        if(i < j) {
            ans++;
        }
        i++;
        j--;
    }
    cout << ans << endl;
}