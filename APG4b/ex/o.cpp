#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
     int a, b, c;
     cin >> a >> b >> c;

     cout << max(max(a, b), c) - min(min(a, b), c) << endl;
}
