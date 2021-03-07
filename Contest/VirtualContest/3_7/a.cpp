#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    if (s == "AAA" || s == "BBB") {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}