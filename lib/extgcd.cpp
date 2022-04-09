/*
ax + by = gcd(a, b)の1次不定方程式を解く関数
long long -> long long
返り値はa, bの最大公約数
x, yに解のうち一つが格納される
a >= bのときO(log(n))で計算できる
*/
#include <iostream>
using namespace std;

long long extgcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    long long x, y;
    extgcd(111, 30, x, y);
    cout << x << " " << y << endl;
}