#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool isPrime(int n) {
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Not Prime" << endl;
        return 0;
    }
    if (isPrime(n)) {
        cout << "Prime" << endl;
        return 0;
    }
    string sn = to_string(n);
    int sum_n = 0;
    rep(i, sn.size()) {
        sum_n += sn[i] - '0';
    }
    if (n % 2 == 0 || (n % 10) == 5 || sum_n % 3 == 0) {
        cout << "Not Prime" << endl;
    }
    else {
        cout << "Prime" << endl;
    }
}