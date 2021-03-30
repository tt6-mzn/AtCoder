#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/*
rust環境の試運転と問題の確認
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
        a[i] = x[i];
        b[i] = y[i];
        c[i] = x[i] + 1;
        d[i] = y[i] + 1;
    }
    /* 出力 */
    rep(i, n) {
        cout << a[i] << " " << b[i] << " ";
        cout << c[i] << " " << d[i] << endl;
    }
}