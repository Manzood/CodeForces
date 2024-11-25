#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = (int)1e6 + 5;

vector<int> visited, visiting;
void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& par) {
    if (visited[node]) return;
    visiting[node] = true;
    visited[node] = true;
    for (auto u : adj[node]) {
        if (visiting[u.first]) {
            // checkcycle
        }
    }
    visiting[node] = false;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    visited.assign(n, false);
    visiting.assign(n, false);
    vector<int> par(n, -1);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
