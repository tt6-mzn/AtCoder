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
    if (to_string(n)[0] != '5' && n % 2 != 0) {
        int s = 0;
        for (char c : to_string(n)) {
            s += c - '0';
        }
        if (s % 3 != 0) {
            cout << "Prime" << endl;
            return 0;
        }
    }
    cout << "Not Prime" << endl;
}

