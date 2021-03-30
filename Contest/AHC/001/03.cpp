#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/*
tupleの形で書き換えた。
scoreの計算(O(n))と長方形同士が重なっていないかの判定(O(n^2))を実装
*/

long long score(
    int n,
    vector<tuple<int, int, int, int>>& ixyr,
    vector<tuple<int, int, int, int>>& abcd
)
{
    double p = 0;
    rep(i, n) {
        int idx, x, y, r;
        int a, b, c, d;
        tie(idx, x, y, r) = ixyr[i];
        tie(a, b, c, d) = abcd[i];
        int s = (a - c) * (b - d);
        if ((a <= x && x < c) && (b <= y && y < d)) {
            p += 1.0 - (1.0 - (double)min(r, s) / (double)max(r, s)) * (1.0 - (double)min(r, s) / (double)max(r, s));
        }
    }
    return (1000000000 * (p / (double)n)) + 0.5;
}

bool isValid(int n, vector<tuple<int, int, int, int>>& abcd) {
    rep(i, n) {
        int ai, bi, ci, di;
        tie(ai, bi, ci, di) = abcd[i];
        rep(j, n) {
            if (j == i) continue;
            int aj, bj, cj, dj;
            tie(aj, bj, cj, dj) = abcd[j];
            if ((ai <= aj && aj < ci) && (bi <= bj && bj < di)) {
                return false;
            }
            if ((ai < cj && cj <= ci) && (bi < dj && dj <= di)) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    /* 入力と宣言 */
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> ixyr(n);
    vector<tuple<int, int, int, int>> abcd(n);
    rep(i, n) {
        int tx, ty, tr;
        cin >> tx >> ty >> tr;
        ixyr[i] = make_tuple(i, tx, ty, tr);
    }

    /* メインの処理 */
    rep(i, n) {
        int idxi, xi, yi, ri;
        tie(idxi, xi, yi, ri) = ixyr[i];
        int a, b, c, d;
        a = xi;
        b = yi;
        c = 10000;
        d = 10000;
        rep(j, n) {
            int idxj, xj, yj, rj;
            tie(idxj, xj, yj, rj) = ixyr[j];
            if (a < xj) c = min(c, xj);
            if (b < yj) d = min(d, yj);
        }
        if ((a - c) * (b - d) > ri) {
            int l = 1;
            while (l * l <= ri) l++;
            c = a + l;
            d = b + l;
        }
        abcd[i] = make_tuple(a, b, c, d);
    }

    /* 出力 */
    cerr << "expected score: " << score(n, ixyr, abcd) << endl;
    cerr << "valid:          " << isValid(n, abcd) << endl;
    rep(i, n) {
        int a, b, c, d;
        tie(a, b, c, d) = abcd[i];
        cout << a << " " << b << " ";
        cout << c << " " << d << endl;
    }
}