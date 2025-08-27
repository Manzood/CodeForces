#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // process even
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) continue;

        if (a[i] <= i) {
            if (a[i - a[i]] & 1) {
                adj[n].push_back(i);
            } else {
                adj[i - a[i]].push_back(i);
            }
        }

        if (i + a[i] < n) {
            if (a[i + a[i]] & 1) {
                adj[n].push_back(i);
            } else {
                adj[i + a[i]].push_back(i);
            }
        }
    }

    vector<int> dist(n + 1, INF);
    dist[n] = 0;
    vector<bool> vis(n + 1, false);
    function<void(int)> bfs = [&](int node) {
        queue<int> q;
        vis[node] = true;
        q.push(node);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto u : adj[cur]) {
                dist[u] = min(dist[u], dist[cur] + 1);
                if (!vis[u]) {
                    vis[u] = true;
                    q.push(u);
                }
            }
        }
    };

    bfs(n);

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (dist[i] < INF) ans[i] = dist[i];
    }

    dist.assign(n + 1, INF);
    dist[n] = 0;
    vis.assign(n + 1, false);
    adj.clear();
    adj.resize(n + 1);

    for (int i = 0; i < n; i++) {
        if (!(a[i] & 1)) continue;

        if (a[i] <= i) {
            if (!(a[i - a[i]] & 1)) {
                adj[n].push_back(i);
            } else {
                adj[i - a[i]].push_back(i);
            }
        }

        if (i + a[i] < n) {
            if (!(a[i + a[i]] & 1)) {
                adj[n].push_back(i);
            } else {
                adj[i + a[i]].push_back(i);
            }
        }
    }

    bfs(n);

    for (int i = 0; i < n; i++) {
        if (dist[i] < INF) ans[i] = dist[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
