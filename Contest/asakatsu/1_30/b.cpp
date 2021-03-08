#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> bool_ac(n, false);
    vector<int> count_wa(n, 0);

    rep(i, m) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC") {
            bool_ac[p] = true;
        }
        else if (bool_ac[p] == false) {
            count_wa[p]++;
        }
    }
    
    int ac = 0, wa = 0;
    rep(i, n) {
        if (bool_ac[i] == true) {
            ac++;
            wa += count_wa[i];
        }
    }
    cout << ac << " " << wa << endl;
}