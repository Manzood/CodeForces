#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[(int)adj[i].size()]++;
    }
    int x = 0, y = 0;
    for (auto tmp : mp) {
        if (tmp.first == 1) continue;
        if (tmp.second == 1)
            x = tmp.first;
        else
            y = tmp.first - 1;
    }
    if (x == 0) x = y + 1;
    printf("%lld %lld\n", x, y);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
