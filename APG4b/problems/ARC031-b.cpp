#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

void bfs(vector<string> &B, int i, int j) {
    if(i < 0 || 10 <= i || j < 0 || 10 <= j || B.at(i).at(j) == 'x') return;
    B.at(i).at(j) = 'x';

    bfs(B, i - 1, j);
    bfs(B, i + 1, j);
    bfs(B, i, j - 1);
    bfs(B, i, j + 1);
}

bool judge(vector<string> &B) {
    bool flg;
    rep(i, 10) {
        rep(j, 10) {
            if(B.at(i).at(j) == 'o') {
                // 陸地なら
                bfs(B, i, j); // bfsを実行
                flg = true;
                rep(k, 10) {
                    if(B.at(k) != "xxxxxxxxxx") {
                        flg = false;
                    }
                }

                return flg;
            }
        }
    }
}

int main() {
    vector<string> A(10), B(10);
    rep(i, 10) {
        cin >> A.at(i);
    }

    bool ans = false;
    rep(i, 10) {
        rep(j, 10) {
            if(A.at(i).at(j) == 'o') continue; // 陸地は埋め立てない

            rep(k, 10) B.at(k) = A.at(k); // コピー

            B.at(i).at(j) = 'o'; // 埋め立てる

            if(judge(B)) { // 判定
                ans = true;
            }
        }
    }

    if(ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
