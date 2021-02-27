#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b;
    cin >> a >> b;
    printf("%.6lf", (((double)(a - b) / (double)a) * 100));
}