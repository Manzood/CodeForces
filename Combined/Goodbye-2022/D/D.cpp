#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

int nodes, edges;
vector<bool> visited;

bool dfs(int node, vector<vector<int>>& adj) {
    if (visited[node]) return false;
    visited[node] = true;
    bool retval = false;
    nodes++;
    for (auto u : adj[node]) {
        edges++;
        if (u == node) retval = true;
        retval |= dfs(u, adj);
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[--a[i]].push_back(--b[i]);
        adj[b[i]].push_back(a[i]);
    }
    int ans = 1, cnt = 0, same = 0;
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            nodes = 0;
            edges = 0;
            if (dfs(i, adj))
                same++;
            else
                cnt++;
            if (nodes != edges / 2) ans = 0;
        }
    }
    for (int i = 0; i < same; i++) ans = (ans * n) % mod;
    for (int i = 0; i < cnt; i++) ans = (ans * 2) % mod;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
