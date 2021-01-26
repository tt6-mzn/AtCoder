#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x;
    cin >> x;
    int i = 1, now = 1;
    while (now < x) {
        i++;
        now += i;
    }
    cout << i << endl;
}