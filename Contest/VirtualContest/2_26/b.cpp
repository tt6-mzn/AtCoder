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
    if (isPrime(n)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
