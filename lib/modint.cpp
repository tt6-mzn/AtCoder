#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class modint {
public:
    long long x;
    long long mod;
    modint(long long x = 0, long long mod = 1000000007) :
        x(((x % mod) + mod) % mod), mod(mod) { }
    modint operator+(modint obj) {
        modint ret((x + obj.x) % mod, mod);
        return ret;
    }
    modint operator-(modint obj) {
        modint ret((((x - obj.x) % mod) + mod) % mod, mod);
        return ret;
    }
    modint operator*(modint obj) {
        modint ret((((x * obj.x) % mod) + mod) % mod, mod);
        return ret;
    }
};

int main() {
    vector<modint> a;
    int mod = 10;
    rep(i, 10) {
        modint t(i, mod);
        a.push_back(t);
    }
    rep(i, 10) {
        rep(j, 10) {
            modint t = a[i] * a[j];
            cout << t.x << " ";
        }
        cout << endl;
    }
}