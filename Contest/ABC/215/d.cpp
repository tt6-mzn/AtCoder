#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//n以下の整数について最小の素因数を求めた結果の配列を返す
//min_factor[i]はiを割り切る最小の数（iの素因数のうち最小のもの）
//min_factor[i] == iならiは素数（i=0, 1のときを除く）
std::vector<int> sieve(int n){
    //素数候補を管理する配列
    std::vector<int> min_factor(n+1);
    //2以上の数を一度素数候補に入れる
    for(int i = 0; i <= n; i++) min_factor[i] = i;
    //それぞれの数について最小の素因数を求める
    for(int i = 2; i*i <= n; i++){
        if(min_factor[i] == i){
            for(int j = 2; i*j <= n; j++){
                if(min_factor[i*j] > i){
                    min_factor[i*j] = i;
                }
            }
        }
    }
    return min_factor;
}

//配列min_factorを使ってmを素因数分解する
//配列ansにはmの素因数が小さい順に格納される
std::vector<int> factor(std::vector<int> &min_factor, int m){
    std::vector<int> ans;
    while(m > 1){
        ans.push_back(min_factor[m]);
        m /= min_factor[m];
    }
    return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

    vector<int> min_factor = sieve(100100);

	vector<int> fact;
	vector<bool> memo(100200, false);

	rep(i, n) {
		vector<int> f = factor(min_factor, a[i]);
		for (int x : f) {
			if (memo[x] == false) {
				memo[x] = true;
				fact.push_back(x);
			}
		}
	}

	vector<int> ans(m + 5, true);
	for (int p : fact) {
		int now = p;
		while (now <= m) {
			ans[now] = false;
			now += p;
		}
	}

	vector<int> out;
	for (int i = 1; i <= m; i++) {
		if (ans[i] == true) {
			out.push_back(i);
		}
	}
	cout << out.size() << endl;
	for (int t : out) {
		cout << t << endl;
	}
}