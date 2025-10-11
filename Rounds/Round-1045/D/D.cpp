#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int bfs(int node, vector<vector<int>>& adj) {
    int n = (int)adj.size();
    int ret = node;

    queue<int> q;
    vector<bool> vis(n, false);
    q.push(node);
    vis[node] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ret = cur;

        for (auto u : adj[cur]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
    }

    return ret;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    int x = bfs(0, adj);
    int y = bfs(x, adj);
    vector<int> path;

    function<bool(int, int)> getPath = [&](int node, int par) {
        bool ret = false;
        if (node == y) {
            path.push_back(y);
            return true;
        }

        for (auto u : adj[node]) {
            if (u == par) continue;
            if (getPath(u, node)) {
                path.push_back(node);
                ret = true;
            }
        }
        return ret;
    };

    getPath(x, -1);

    vector<int> ans;
    int len = (int)path.size();
    for (int i = 0; i < (int)path.size(); i++) {
        int p = path[i];
        if ((int)adj[p].size() > 2) {
            for (auto u : adj[p]) {
                if ((i == len - 1 || u != path[i + 1]) &&
                    (i == 0 || u != path[i - 1])) {
                    ans = {path[i - 1], p, u};
                }
            }
        }
    }

    if (ans.empty()) {
        printf("-1\n");
    } else {
        printf("%lld %lld %lld\n", ans[0] + 1, ans[1] + 1, ans[2] + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
