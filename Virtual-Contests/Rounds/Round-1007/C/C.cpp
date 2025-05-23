#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, st, en;
    scanf("%lld%lld%lld", &n, &st, &en);
    st--, en--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    function<void(int, int)> dfs = [&](int node, int par) {
        for (auto u : adj[node]) {
            if (u == par) continue;
            dfs(u, node);
        }
        ans.push_back(node);
    };

    dfs(en, -1);
    for (auto x : ans) {
        printf("%lld ", x + 1);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
