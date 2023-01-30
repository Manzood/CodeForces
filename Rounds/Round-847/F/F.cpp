#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
// #define int long long

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& d,
         int& ans) {
    for (auto u : adj[node]) {
        if (u == par) continue;
        ans = min(ans, d[u] + 1 + d[node]);
        if (d[u] > d[node] + 1 && d[node] + 1 < ans) {
            d[u] = d[node] + 1;
            dfs(u, node, adj, d, ans);
        }
        d[u] = min(d[u], d[node] + 1);
    }
}

void dfs2(int node, int par, vector<vector<int>>& adj, vector<int>& d) {
    for (auto u : adj[node]) {
        if (u != par) {
            d[u] = d[node] + 1;
            dfs2(u, node, adj, d);
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%d", &n);
    vector<int> c(n);
    scanf("%d", &c[0]);
    vector<int> color(n, 1);
    color[--c[0]] = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", &c[i]);
        c[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = n;
    vector<int> d(n, n);
    d[c[0]] = 0;
    dfs2(c[0], -1, adj, d);
    for (int i = 1; i < n; i++) {
        d[c[i]] = 0;
        dfs(c[i], -1, adj, d, ans);
        printf("%d ", ans);
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
