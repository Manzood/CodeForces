#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector <int> visited;
void dfs(int node, vector <vector <int>>& adj, vector <int>& atdist, int dist) {
    visited[node] = true;
    int cnt = 0;
    for (auto u: adj[node]) {
        if (!visited[u]) {
            cnt++;
            dfs(u, adj, atdist, dist + 1);
        }
    }
    atdist[dist + 1] += cnt - 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <vector <int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    visited.resize(n, false);
    int ans = n;
    for (int i = 0; i < n; i++) {
        visited.assign(n, false);
        vector <int> atdist(n + 1, 0);
        dfs(i, adj, atdist, 0);
        int cur = 0;
        for (int j = 0; j < n; j++) {
            cur = max(cur, atdist[j]);
        }
        ans = min(ans, cur + 1);
    }
    if (n == 1) ans = 0;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
