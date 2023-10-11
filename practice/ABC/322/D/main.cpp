#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

pair<int, int> upper_left(const vector<string> &p) {
	int i = 0, j = p[0].size();
	while (p[i].find("#") == string::npos) i++;
	rep(i_, p.size()) {
		auto pos = p[i_].find("#");
		if (pos != string::npos) j = min(j, (int)pos);
	}
	return {i, j};
}

pair<int, int> lower_right(const vector<string> &p) {
	int i = p.size(), j = 0;
	while (p[--i].find("#") == string::npos) ;
	rep(i_, p.size()) {
		auto pos = p[i_].rfind("#");
		if (pos != string::npos) j = max(j, (int)pos);
	}
	return {i, j};
}

vector<string> crop(const vector<string> &p) {
	int uli, ulj, lri, lrj;
	tie(uli, ulj) = upper_left(p);
	tie(lri, lrj) = lower_right(p);
	vector<string> ret;
	for (int i = uli; i <= lri; i++) {
		ret.push_back(p[i].substr(ulj, lrj - ulj + 1));
	}
	return ret;
}

vector<string> rotate(const vector<string> &p) {
	vector<string> ret(p[0].size());
	rep(i, ret.size()) {
		rep(j, p.size()) ret[i].push_back(p[j][p[0].size() - i - 1]);
	}
	return ret;
}

int count(const vector<string> &p) {
	int ret = 0;
	for (string s : p) {
		ret += count_if(s.begin(), s.end(), [](char c){ return c == '#'; });
	}
	return ret;
}

bool is_valid(const vector<string> &q, int i, int j) {
	return q.size() + i <= 4 && q[0].size() + j <= 4;
}

void put(vector<vector<bool>> &flg, const vector<string> &p, int i, int j) {
	rep(i_, p.size()) rep(j_, p[0].size()) {
		flg[i + i_][j + j_] = flg[i + i_][j + j_] || (p[i_][j_] == '#');
	}
}

bool is_ok(const vector<vector<bool>> &flg) {
	rep(i, 4) rep(j, 4) {
		if (!flg[i][j]) return false;
	}
	return true;
}

int main() {
	vector<string> p1(4), p2(4), p3(4);
	rep(i, 4) cin >> p1[i];
	rep(i, 4) cin >> p2[i];
	rep(i, 4) cin >> p3[i];

	if (count(p1) + count(p2) + count(p3) != 16) {
		cout << "No" << endl;
		return 0;
	}
	
	vector<vector<string>> p1_rot(4), p2_rot(4), p3_rot(4);
	p1_rot[0] = crop(p1);
	p2_rot[0] = crop(p2);
	p3_rot[0] = crop(p3);
	rep(i, 3) p1_rot[i + 1] = rotate(p1_rot[i]);
	rep(i, 3) p2_rot[i + 1] = rotate(p2_rot[i]);
	rep(i, 3) p3_rot[i + 1] = rotate(p3_rot[i]);

	for (auto& q1 : p1_rot) {
		rep(i1, 4) rep(j1, 4) {
			if (!is_valid(q1, i1, j1)) continue;
			for (auto& q2 : p2_rot) {
				rep(i2, 4) rep(j2, 4) {
					if (!is_valid(q2, i2, j2)) continue;
					for (auto& q3 : p3_rot) {
						rep(i3, 4) rep(j3, 4) {
							if (!is_valid(q3, i3, j3)) continue;
							vector<vector<bool>> flg(4, vector<bool>(4, false));
							put(flg, q1, i1, j1);
							// rep(_, flg.size()) { rep(__, flg[_].size()) { cout << flg[_][__] << " "; } cout << endl; }
							// return 0;
							put(flg, q2, i2, j2);
							put(flg, q3, i3, j3);

							
							if (is_ok(flg)) {
								cout << "Yes" << endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}

	cout << "No" << endl;
	return 0;
}