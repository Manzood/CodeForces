#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector <bool> visited;
int dfs (int node, vector <vector <int>>& adj, vector <int>& a, int sum, int m) {
    int retval = 0;
    if (visited[node]) return retval;
    visited[node] = true;
    if (a[node] == 1) sum++;
    else sum = 0;
    if (sum > m) return 0;
    int cnt = 0;
    for (auto u: adj[node]) {
        retval += dfs(u, adj, a, sum, m);
        // debug(node, retval);
        cnt++;
    }
    // debug (node, sum);
    if (cnt == 1 && node > 0) retval++;
    return retval;
}


void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <int> a(n);
    vector <vector <int>> adj(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    visited.resize(n, false);
    visited.assign(n, false);
    int ans = dfs(0, adj, a, 0, m);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
