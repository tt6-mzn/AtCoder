#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int h, w, cnt = 0;
    string s1, s2, s3;
    cin >> h >> w;
    rep(i, h) { // 各行について繰り返し
        if(i != 0 && i != h - 1) { // 0行目とh-1行目以外の処理
            s1 = s2;
            s2 = s3;
            cin >> s3;
            rep(j, w) { // 各列について繰り返し
                cnt = 0;
                if(j != 0 && j != w - 1) { // 0列目とw-1列目以外の処理
                    for(int k = -1; k < 2; k++) {
                        if(s1.at(j + k) == '#') cnt++;
                        if(s2.at(j + k) == '#') cnt++;
                        if(s3.at(j + k) == '#') cnt++;
                    }
                }
                else if(j == 0) { // 0列目の処理
                    if(s1.at(0) == '#') cnt++;
                    if(w != 1 && s1.at(1) == '#') cnt++;
                    if(s2.at(0) == '#') cnt++;
                    if(w != 1 && s2.at(1) == '#') cnt++;
                    if(s3.at(0) == '#') cnt++;
                    if(w != 1 && s3.at(1) == '#') cnt++;
                }
                else { // w-1列目の処理
                    if(s1.at(w-2) == '#') cnt++;
                    if(s1.at(w-1) == '#') cnt++;
                    if(s2.at(w-2) == '#') cnt++;
                    if(s2.at(w-1) == '#') cnt++;
                    if(s3.at(w-2) == '#') cnt++;
                    if(s3.at(w-1) == '#') cnt++;
                }
                if(s2.at(j) == '.') cout << cnt;
                else cout << '#';
            }
        }
        else if(i == 0) { // 0行目の処理
            if(h != 1) {
                cin >> s2 >> s3;
            }
            else {
                cin >> s2;
                s3 = "";
            }
            rep(j, w) { // 各列について繰り返し
                cnt = 0;
                if(j != 0 && j != w - 1) { // 0列目とw-1列目以外の処理
                    for(int k = -1; k < 2; k++) {
                        if(s2.at(j + k) == '#') cnt++;
                        if(h != 1 && s3.at(j + k) == '#') cnt++;
                    }
                }
                else if(j == 0) { // 0列目の処理
                    if(w != 1 && s2.at(1) == '#') cnt++;
                    if(h != 1 && s3.at(0) == '#') cnt++;
                    if(w != 1 && h != 1 && s3.at(1) == '#') cnt++;
                }
                else {
                    if(s2.at(w-2) == '#') cnt++;
                    if(h != 1 && s3.at(w-2) == '#') cnt++;
                    if(h != 1 && s3.at(w-1) == '#') cnt++;
                }
                if(s2.at(j) == '.') cout << cnt;
                else cout << '#';
            }
        }
        else { // h-1行目の処理
            s1 = s2;
            s2 = s3;
            s3 = "";
            rep(j, w) { // 各列について繰り返し
                cnt = 0;
                if(j != 0 && j != w - 1) { // 0列目とw-1列目以外の処理
                    for(int k = -1; k < 2; k++) {
                        if(s1.at(j + k) == '#') cnt++;
                        if(s2.at(j + k) == '#') cnt++;
                    }
                }
                else if(j == 0) { // 0列目の処理
                    if(s1.at(0) == '#') cnt++;
                    if(w != 1 && s1.at(1) == '#') cnt++;
                    if(w != 1 && s2.at(1) == '#') cnt++;
                }
                else { // w-1列目の処理
                    if(s1.at(w-2) == '#') cnt++;
                    if(s1.at(w-1) == '#') cnt++;
                    if(s2.at(w-2) == '#') cnt++;
                }
                if(s2.at(j) == '.') cout << cnt;
                else cout << '#';
            }
        }
        cout << endl; // 改行
    }
}
