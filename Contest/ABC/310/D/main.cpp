#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, t, m;
vector<vector<bool>> G(10, vector<bool>(10, false));
vector<vector<bool>> teams;
vector<int> nokori;
int ans = 0;

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

int recursion(int index) {
	int ret = 0;
	if (index == nokori.size()) return 1;
	rep(i, t) {
		bool flg = true;
		rep(j, n) {
			if (teams[i][j] && G[j][nokori[index]]) flg = false;
		}
		if (flg) {
			teams[i][nokori[index]] = true;
			ret += recursion(index + 1);
			teams[i][nokori[index]] = false;
		}
	}
	return ret;
}

bool my_callback(const vector<int>& comb) {
	teams.assign(t, vector<bool>(n, false));
	rep(i, t) teams[i][comb[i]] = true;
	nokori.assign(0, 0);
	rep(i, n) if (find(comb.begin(), comb.end(), i) == comb.end()) nokori.push_back(i);

	// rep(_, comb.size()) { cout << comb[_] << " "; } cout << endl;
	// rep(_, nokori.size()) { cout << nokori[_] << " "; } cout << endl;
	// cout << endl;

	ans = recursion(0);
    return false;
}

int main() {
	cin >> n >> t >> m;
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		ai--; bi--;
		G[ai][bi] = true;
		G[bi][ai] = true;
	}

	vector<int> member(n);
	rep(i, n) member[i] = i;

    combination(member, t, my_callback);

	cout << ans << endl;
	return 0;
}
