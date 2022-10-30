#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int getheight(int node, vector<vector<int>>& adj, vector<int>& height) {
    int retval = 0;
    for (auto u : adj[node]) {
        retval = max(retval, getheight(u, adj, height) + 1);
    }
    return height[node] = retval;
}

int dfs(int node, vector<vector<int>>& adj, vector<int>& height) {
    int retval = 0;
    int sum = 0;
    for (auto u : adj[node]) {
        sum += dfs(u, adj, height);
    }
    retval = max(sum, height[node] + 1);
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> p(n);
    p[0] = -1;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
        adj[p[i]].push_back(i);
    }
    vector<int> height(n, 0);
    getheight(0, adj, height);
    int ans = dfs(0, adj, height);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
