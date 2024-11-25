#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<bool> visited;
bool dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& pos) {
    bool retval = true;
    if (visited[node]) return retval;
    visited[node] = true;
    for (auto u : adj[node]) {
        if (visited[u.first] && pos[u.first] != pos[node] + u.second)
            return false;
        if (!visited[u.first]) pos[u.first] = pos[node] + u.second;
        retval &= dfs(u.first, adj, pos);
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, d;
        scanf("%lld%lld%lld", &a, &b, &d);
        a--, b--;
        adj[b].push_back({a, d});
        adj[a].push_back({b, -d});
    }
    visited.assign(n, false);
    vector<int> pos(n, 0);
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            pos[i] = 0;
            ans &= dfs(i, adj, pos);
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
