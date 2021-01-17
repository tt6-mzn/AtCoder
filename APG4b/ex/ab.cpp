#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    pair<int, int> ret;
    ret.first = a.first + b.first;
    ret.second = a.second + b.second;
    return ret;
}

int main() {
    pair<int, int> a = {1, 2};
    pair<int, int> b = {3, 4};

    auto c = a + b;
    cout << c.first << ", " << c.second << endl;
}