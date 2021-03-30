#include <iostream>
#include <vector>
#include <tuple>
#include <random>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    mt19937 mt;
    random_device rnd;
    mt.seed(rnd());
    for (int i = 0; i < 10; i++) {
        cout << (int)mt() << endl;
    }
}