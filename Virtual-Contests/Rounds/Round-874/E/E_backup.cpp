#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

class dsu {
   public:
    vector<int> p;
    vector<int> size;
    vector<bool> back_edge;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.resize(n, 1);
        back_edge.resize(n, false);
    }
    int parent(int x) {
        // path compression takes place here
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
            back_edge[x] = back_edge[x] | back_edge[y];
            return true;
        }
        return false;
    }
};

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
    }
    dsu d(n);
    vector<int> incoming(n, 0);
    for (int i = 0; i < n; i++) {
        incoming[a[i]]++;
        d.unite(i, a[i]);
        if (incoming[a[i]] > 1) d.back_edge[d.parent(i)] = true;
    }
    set<int> s;
    int mi = 1;
    bool everything = true;
    for (int i = 0; i < n; i++) {
        int par = d.parent(i);
        if (s.count(par)) continue;
        // if (test == 11) debug(d.size, d.p);
        // if (test == 11) debug(par, d.back_edge[par], d.size[par]);
        s.insert(par);
        if (d.size[par] > 2 && d.back_edge[par] == false)
            mi++;
        else
            everything = false;
    }
    if (everything) mi--;
    printf("%lld %lld\n", mi, (int)s.size());
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
