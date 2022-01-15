#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

// misunderstood the problem :/
vector<bool> visited;
void dfs (int node, vector<vector<int>>& adj, int depth, map<pair<int, int>, int>& edges) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto u: adj[node]) {
        if (!visited[u]) edges[{min(node, u), max(node, u)}] = depth % 2;
        dfs (u, adj, depth + 1, edges);
    }
}

void solve() {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> adj(n);
    bool possible = true;
    vector<vector<int>> edges;
    visited.resize(n, false);
    visited.assign(n, false);
    // vector<int> primes = {3, 5, 11};
    // int p_index = 0;
    int leaf = -1;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
        if ((int)adj[u].size() > 2 || (int)adj[v].size() > 2) {
            possible = false;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((int) adj[i].size() == 1) leaf = i;
    }
    // basic dfs
    map<pair<int,int>, int> mp;
    vector<int> ans;
    if (possible) {
        dfs (leaf, adj, 0, mp);
        for (auto x: edges) {
            if (mp[{min(x[0], x[1]), max(x[0], x[1])}] == 0) {
                ans.push_back (2);
            } else {
                ans.push_back (3);
            }
        }
    } else {
        ans.push_back(-1);
    }
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
