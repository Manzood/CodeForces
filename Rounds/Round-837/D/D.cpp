#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<vector<int>> f;
vector<vector<int>> dist;

void dfs(int node, int par, int d, int nxt, int src, vector<vector<int>>& adj) {
    dist[src][node] = d;
    if (nxt != -1) {
        f[src][node] = nxt;
    }
    int tmp = nxt;
    for (auto u : adj[node]) {
        if (u == par) continue;
        if (tmp == -1) nxt = u;
        dfs(u, node, d + 1, nxt, src, adj);
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    f.assign(n, vector<int>(n, -1));
    dist.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        dfs(i, -1, 0, -1, i, adj);
    }
    // now dp
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // sort by distance
    vector<vector<pair<int, int>>> d(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[dist[i][j]].push_back({i, j});
        }
    }
    for (int i = 0; i < (int)d[0].size(); i++) {
        dp[d[0][i].first][d[0][i].second] = 1;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < (int)d[i].size(); j++) {
            int src = d[i][j].first;
            int dest = d[i][j].second;
            dp[src][dest] = max(dp[f[src][dest]][dest], dp[src][f[dest][src]]);
            if (s[src] == s[dest]) {
                if (f[src][dest] != dest) {
                    dp[src][dest] =
                        max(dp[src][dest], dp[f[src][dest]][f[dest][src]] + 2);
                } else {
                    dp[src][dest] = 2;
                }
            }
            ans = max(ans, dp[src][dest]);
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
