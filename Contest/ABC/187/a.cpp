#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    string a, b;
    cin >> a >> b;
    int sum_a = 0, sum_b = 0;
    for(int i = 0; i < a.size(); i++) {
        sum_a += a.at(i) - '0';
    }
    for(int i = 0; i < b.size(); i++) {
        sum_b += b.at(i) - '0';
    }
    cout << max(sum_a, sum_b) << endl;
}