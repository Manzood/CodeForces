#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void dfs(int node, int parent, vector<vector<int>>& adj,
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
            } else {
                color[node].push_back(parent);
                colored[parent] = true;
                colored[node] = true;
            }
        } else {
            dfs(u, node, adj, color, colored, visited, visiting);
        }
    }
    visiting[node] = false;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> get_index;
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
    dfs(0, -1, adj, color, colored, visited, visiting);
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
