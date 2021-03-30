#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/*
重なる部分が確実になくなるように長方形を作る。
要望の面積より大きくなっていた場合は平方根で近似(配置によってはエラーになる)
*/

int main() {
    /* 入力と宣言 */
    int n;
    cin >> n;
    vector<int> x(n), y(n), r(n);
    rep(i, n) cin >> x[i] >> y[i] >> r[i];
    vector<int> a(n), b(n), c(n), d(n); // 出力用変数
    /* メインの処理 */
    rep(i, n) {
        int at, bt, ct, dt;
        at = x[i];
        bt = y[i];
        ct = 10000;
        dt = 10000;
        rep(j, n) {
            if (at < x[j]) ct = min(ct, x[j]);
            if (bt < y[j]) dt = min(dt, y[j]);
        }
        if ((at - ct) * (bt - dt) > r[i]) {
            int l = 1;
            while (l * l <= r[i]) l++;
            ct = at + l;
            dt = bt + l;
        }
        a[i] = at;
        b[i] = bt;
        c[i] = ct;
        d[i] = dt;
    }
    /* 出力 */
    rep(i, n) {
        cout << a[i] << " " << b[i] << " ";
        cout << c[i] << " " << d[i] << endl;
    }
}