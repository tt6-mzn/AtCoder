#include <iostream>
#include <vector>
#include <tuple>
#include <random>
#include <cmath>
#include <time.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/*
簡易的な焼きなましを実装
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
        if (ai < 0 || 10000 <= ai || bi < 0 || 10000 <= bi) {
            return false;
        }
        if (ci <= 0 || 10000 < ci || di <= 0 || 10000 < di) {
            return false;
        }
        if (ci <= ai || di <= bi) {
            return false;
        }
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
            if ((ai < cj && cj <= ci) && (bi <= bj && bj < di)) {
                return false;
            }
            if ((ai <= aj && aj < ci) && (bi < dj && dj <= di)) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    /* 時間計測開始 */
    clock_t start = clock();
    
    /* 入力と宣言 */
    mt19937 mt;
    random_device rnd; // メルセンヌツイスタ
    mt.seed(rnd());
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> ixyr(n);
    vector<tuple<int, int, int, int>> abcd(n);
    rep(i, n) {
        int tx, ty, tr;
        cin >> tx >> ty >> tr;
        ixyr[i] = make_tuple(i, tx, ty, tr);
    }
    int m = 100;

    /* メインの処理 */
    // 大雑把に形を決定
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
        abcd[i] = make_tuple(a, b, c, d);
    }
    
    // やきなまし
    int pre_score = score(n, ixyr, abcd);
    rep(_, m) {
        int idx = abs((int)mt()) % n;
        int dx = (int)mt() % 50;
        int dy = (int)mt() % 50;
        int ab = abs((int)mt()) % 2;
        int a, b, c, d;
        tie(a, b, c, d) = abcd[idx];
        if (ab == 1) {
            a += dx;
            b += dy;
        }
        else {
            c += dx;
            d += dy;
        }
        abcd[idx] = make_tuple(a, b, c, d);
        if (isValid(n, abcd)) {
            int cur_score = score(n, ixyr, abcd);
            if (cur_score > pre_score) {
                pre_score = cur_score;
                continue;
            }
        }
        if (ab == 1) {
            a -= dx;
            b -= dy;
        }
        else {
            c -= dx;
            d -= dy;
        }
        abcd[idx] = make_tuple(a, b, c, d);
    }

    /* 出力 */
    rep(i, n) {
        int a, b, c, d;
        tie(a, b, c, d) = abcd[i];
        cout << a << " " << b << " ";
        cout << c << " " << d << endl;
    }

    /* 時間計測終了 */
    clock_t end = clock();
    
    std::cerr << "score: " << score(n, ixyr, abcd) << endl;
    std::cerr << "valid: " << isValid(n, abcd) << endl;
    std::cerr << "time : " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
}