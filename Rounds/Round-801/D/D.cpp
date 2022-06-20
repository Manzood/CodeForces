#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector <int> visited;
void dfs(int node, vector <vector <int>>& adj, vector <int>& ans) {
    visited[node] = true;
    int cnt = 0;
    for (auto u: adj[node]) {
        if (visited[u]) continue;
        dfs(u, adj, ans);
        ans[node] += ans[u];
        if (ans[u] == 0) cnt++;
    }
    ans[node] += max(0LL, cnt - 1);
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
    int ans = (int) 1e9 + 7;
    int root = -1;
    for (int i = 0; i < n; i++) {
        if ((int) adj[i].size() >= 3) root = i;
    }
    if (root > -1) {
        visited.assign(n, false);
        vector <int> t_ans(n, 0);
        dfs(root, adj, t_ans);
        ans = min(ans, t_ans[root]);
    } else {
        ans = 1;
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
