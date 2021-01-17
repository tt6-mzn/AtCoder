#include <bits/stdc++.h>
using namespace std;

vector<long long> divisors(long long n) {
    vector<long long> res1;
    vector<long long> res2;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res1.push_back(i);
            if(i * i != n) {
                res2.push_back(n / i);
            }
        }
    }
    reverse(res2.begin(), res2.end());
    res1.insert(res1.end(), res2.begin(), res2.end());
    return res1;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> res = divisors(n);
    for(int i = 0; i < res.size(); i++) {
        cout << res.at(i) << endl;
    }
}