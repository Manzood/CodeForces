#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;

class dsu {
   public:
    vector<int> p, size;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.resize(n, 1);
    }
    int parent(int x) {
        // path compression
        if (x == p[x])
            return x;
        else
            return p[x] = parent(p[x]);
    }
    inline bool unite(int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x != y) {
            if (size[x] > size[y]) swap(x, y);
            p[x] = y;
            size[y] += size[x];
            return true;
        }
        return false;
    }
};

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> p(n), c(n), fact(n + 1, 1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i = 1; i <= n; i++) {
        (fact[i] = fact[i - 1] * i) %= MOD;
    }

    int ans = 1;
    int size = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0 && c[i] == c[i - 1]) {
            size++;
        } else {
            (ans *= fact[size]) %= MOD;
            size = 1;
        }
    }
    (ans *= fact[size]) %= MOD;

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
