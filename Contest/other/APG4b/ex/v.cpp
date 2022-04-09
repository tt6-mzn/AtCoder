#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
    int n = board.size();
    if(x <= -1 || x >= n || y <= -1 || y >= n) {
        return false;
    }
    if(board.at(y).at(x) == '#') {
        return false;
    }
    if(checked.at(y).at(x)) {
        return false;
    }
    return true;
}

bool reachable(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
    int n = board.size();

    if(x == n - 1 && y == n - 1) {
        return true;
    }

    checked.at(y).at(x) = true;

    bool result = false;

    if(is_valid_move(board, checked, x - 1, y) && reachable(board, checked, x - 1, y)) {
        result = true;
    }
    if(is_valid_move(board, checked, x + 1, y) && reachable(board, checked, x + 1, y)) {
        result = true;
    }
    if(is_valid_move(board, checked, x, y - 1) && reachable(board, checked, x, y - 1)) {
        result = true;
    }
    if(is_valid_move(board, checked, x, y + 1) && reachable(board, checked, x, y + 1)) {
        result = true;
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n);
    for(int i = 0; i < n; i++) {
        cin >> board.at(i);
    }

    vector<vector<bool>> checked(n, vector<bool>(n, false));

    if(reachable(board, checked, 0, 0)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
