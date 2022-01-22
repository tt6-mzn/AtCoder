#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/* 自然数nの約数の個数を数える
 * O(√n)
*/
long long count_divisors(long long n) {
    long long ret = 1, i = 2;
    if (n == 1) return 1;
    while (i * i < n) {
        if (n % i == 0) ret++;
        i++;
    }
    if (i * i == n) return 2 * ret + 1;
    return 2 * ret;
}

/*
自然数nの約数の配列を返す関数
配列は昇順に並んでいる
O(sqrt(n))
*/
vector<long long> enum_divisors(long long n) {
    vector<long long> v1, v2;
    v1.push_back(1);
    v2.push_back(n);
    long long i = 2;
    while (i * i < n) {
        if (n % i == 0) {
            v1.push_back(i);
            v2.push_back(n / i);
        }
        i++;
    }
    if (i * i == n) v1.push_back(i);
    reverse(v2.begin(), v2.end());
    copy(v2.begin(), v2.end(), back_inserter(v1));
    return v1;
}


int main() {
    vector<long long> a = enum_divisors(10);
    cout << a[0];
    for (int i = 1; i < a.size(); i++) cout << " " << a[i];
    cout << endl;
}