#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    vector<int> mx(n, 0), mi(n, 0);
    mx[0] = a[0];

    function<void(int, int)> dfs = [&](int node, int par) {
        mx[node] = a[node] - min(mi[par], 0LL);
        mi[node] = a[node] - max(mx[par], 0LL);
        for (auto u : adj[node])
            if (u != par) dfs(u, node);
    };

    for (auto u : adj[0]) {
        dfs(u, 0);
    }

    for (int i = 0; i < n; i++) {
        printf("%lld%c", mx[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
