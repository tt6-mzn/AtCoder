#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<int>> a;
int ans = -1;

template<class T>
void combination(const vector<T>& seed, int target_size, bool (*callback)(const vector<T>&)) {
    vector<int> indices(target_size);
    const int seed_size = seed.size();
    int start_index = 0;
    int size = 0;

    while (size >= 0) {
        for (int i = start_index; i < seed_size; ++i) {
            indices[size++] = i;
            if (size == target_size) {
                vector<T> comb(target_size);
                for (int x = 0; x < target_size; ++x) {
                    comb[x] = seed[indices[x]];
                }
                if (callback(comb)) return;
                break;
            }
        }
        --size;
        if (size < 0) break;
        start_index = indices[size] + 1;
    }
}

bool my_callback(const vector<int>& comb) {
    int n = comb.size();
	vector<int> member(n), member2;
	vector<bool> memo(2 * n, false);
	rep(i, n) {
		member[i] = comb[i];
		memo[member[i]] = true;
	}
	rep(i, 2 * n) {
		if (!memo[i]) member2.push_back(i);
	}

	do {
		int v = 0;
		rep(i, n) {
			v ^= a[member[i]][member2[i]];
		}
		if (v > ans) ans = v;
	} while (next_permutation(member2.begin(), member2.end()));
	
    return false;
}

int main() {
	// input
	int n;
	cin >> n;
	a.assign(2 * n, vector<int>(2 * n, 0));
	rep(i, 2 * n) {
		for (int j = i; j < 2 * n; j++) {
			if (i != j) {
				cin >> a[i][j];
				a[j][i] = a[i][j];
			}
		}
	}
	
    vector<int> vals;
	rep(i, 2 * n) vals.push_back(i);

    combination(vals, n, my_callback);

	cout << ans << endl;
}