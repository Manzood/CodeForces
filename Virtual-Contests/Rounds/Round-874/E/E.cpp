#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// count how many cycles there.
// if there's any elements outside a cycle, add 1

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    if (vis[node]) return;
    vis[node] = true;
    for (auto u : adj[node]) dfs(u, adj, vis);
}

bool checkcycle(int node, vector<int>& a, vector<bool>& vis,
                vector<bool>& visiting, vector<bool>& in_cycle) {
    if (vis[node]) return false;
    vis[node] = true;
    bool retval = false;
    visiting[node] = true;
    if (visiting[a[node]] && a[a[node]] != node) retval = true;
    retval |= checkcycle(a[node], a, vis, visiting, in_cycle);
    visiting[node] = false;
    return in_cycle[node] = retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
        adj[i].push_back(a[i]);
        adj[a[i]].push_back(i);
    }
    int components = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            components++;
            dfs(i, adj, vis);
        }
    }
    vis.assign(n, false);
    vector<bool> visiting(n, false);
    vector<bool> in_cycle(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (checkcycle(i, a, vis, visiting, in_cycle)) cnt++;
    }
    int add = 0;
    for (int i = 0; i < n; i++)
        if (!in_cycle[i]) add = 1;
    cnt += add;
    printf("%lld %lld\n", cnt, components);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
