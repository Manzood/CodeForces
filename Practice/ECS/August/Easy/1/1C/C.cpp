#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

struct Dsu {
    int n;
    vector<int> p, size;

    Dsu(int sz) {
        n = sz;
        size.assign(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline bool unite(int x, int y) {
        x = par(x);
        y = par(y);
        if (x == y) return false;

        if (size[x] > size[y]) swap(x, y);
        p[x] = y;
        size[y] += size[x];
        return true;
    }

    int par(int x) {
        if (x == p[x])
            return x;
        else
            return p[x] = par(p[x]);
    }
};

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);

    Dsu d0(n), d1(n);
    vector<bool> has0(n, false), has1(n, false);
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y, c;
        scanf("%lld%lld%lld", &x, &y, &c);
        x--, y--;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});

        if (c == 0) {
            d0.unite(x, y);
            has0[x] = true, has0[y] = true;
        } else {
            d1.unite(x, y);
            has1[x] = true, has1[y] = true;
        }
    }

    vector<bool> vis0(n, false), vis1(n, false);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x = d0.par(i), y = d1.par(i);

        if (!vis0[x]) ans += d0.size[x] * (d0.size[x] - 1);
        if (!vis1[y]) ans += d1.size[y] * (d1.size[y] - 1);

        vis0[x] = true, vis1[y] = true;
    }

    for (int i = 0; i < n; i++) {
        if (has0[i] && has1[i]) {
            int x = d0.par(i), y = d1.par(i);
            ans += (d0.size[x] - 1) * (d1.size[y] - 1);
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
