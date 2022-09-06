#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void dfs(int node, int parent, int& count, vector<vector<int>>& adj,
         vector<vector<int>>& color, vector<bool>& colored,
         vector<bool>& visited, vector<bool>& visiting) {
    if (visited[node]) return;
    visited[node] = true;
    visiting[node] = true;
    for (auto u : adj[node]) {
        if (visiting[u] && u != parent) {
            // cycle detected
            if (!colored[u] || !colored[node]) {
                color[node].push_back(u);
                colored[u] = true;
                colored[node] = true;
            } else if (!colored[parent]) {
                color[node].push_back(parent);
                colored[parent] = true;
                colored[node] = true;
            } else {
                count = parent;
            }
        } else {
            dfs(u, node, count, adj, color, colored, visited, visiting);
        }
    }
    if (count == node) {
        for (auto u : adj[node]) {
            if (visiting[u] && !colored[u]) {
                color[node].push_back(u);
                colored[node] = true;
                colored[u] = true;
                count = -1;
            }
        }
    }
    visiting[node] = false;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> adj(n);
    map<vector<int>, int> get_index;
    vector<vector<int>> color(n);
    vector<bool> colored(n, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        get_index[{u, v}] = i;
        get_index[{v, u}] = i;
    }
    string ans(m, '0');
    vector<bool> visited(n, false), visiting(n, false);
    int count = -1;
    dfs(0, -1, count, adj, color, colored, visited, visiting);
    // assert(count == -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)color[i].size(); j++) {
            int ind = get_index[{i, color[i][j]}];
            ans[ind] = '1';
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
