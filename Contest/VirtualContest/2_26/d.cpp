#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, k;
    cin >> n >> k;
    long long cnt = 0;
    cnt += ((k - 1) * (n - k)) * 6;
    cnt += (n - k) * 3;
    cnt += (k - 1) * 3;
    cnt++;
    long long n3 = n * n * n;
    printf("%.10lf", (double)cnt / (double)n3);
}