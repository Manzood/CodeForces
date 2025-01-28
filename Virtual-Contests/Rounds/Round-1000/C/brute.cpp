#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    if (vis[node]) return;
    vis[node] = true;
    for (auto x : adj[node]) {
        dfs(x, adj, vis);
    }
}

int remove(int u, int v, vector<vector<int>> adj) {
    int n = (int)adj.size();
    vector<bool> vis(n, false);
    vis[u] = true, vis[v] = true;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ret++;
            dfs(i, adj, vis);
        }
    }
    return ret;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int val = remove(i, j, adj);
            if (val > ans) {
                /* debug(i + 1, j + 1, val); */
                ans = val;
            }
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
