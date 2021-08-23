#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    if(sx == gx) {
        cout << sx << endl;
    }
    else {
        printf("%lf", sx - sy * ((double)(sx - gx) / (double)(sy + gy)));
    }
}