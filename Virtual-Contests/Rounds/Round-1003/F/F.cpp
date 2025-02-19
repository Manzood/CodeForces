#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, string& ans,
         vector<int>& a) {
    if (vis[node]) return;
    vis[node] = true;
    set<int> f;
    for (auto u : adj[node]) {
        if (a[u] == a[node]) ans[a[u] - 1] = '1';
        if (f.count(a[u])) ans[a[u] - 1] = '1';
        f.insert(a[u]);
    }
    for (auto u : adj[node]) {
        dfs(u, adj, vis, ans, a);
    }
}

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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string ans(n, '0');
    vector<bool> vis(n, false);
    dfs(0, adj, vis, ans, a);
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
