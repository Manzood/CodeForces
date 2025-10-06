#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());  // NOLINT

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);

    for (int j = 0; j < 10; j++) {
        int root = uniform_int_distribution<int>(0, n - 1)(rng);
        vector<bool> vis(n, false), marked(n, false);
        function<void(int)> dfs = [&](int node) {
            if (vis[node]) return;
            vis[node] = true;

            bool found = false;
            for (auto u : adj[node])
                if (marked[u]) found = true;

            if (!found) marked[node] = true;

            for (auto u : adj[node]) dfs(u);
        };

        dfs(root);

        vector<int> x, y;
        for (int i = 0; i < n; i++)
            if (marked[i]) x.push_back(i);

        ans = ans.size() < x.size() ? ans : x;

        vis.assign(n, false), marked.assign(n, false);
        int other =
            uniform_int_distribution<int>(0, (int)adj[root].size() - 1)(rng);
        root = adj[root][other];
        dfs(root);

        for (int i = 0; i < n; i++)
            if (marked[i]) y.push_back(i);

        ans = ans.size() < y.size() ? ans : y;
    }

    // vector<bool> fin(n, false);
    // for (auto cur : ans) fin[cur] = true;
    // for (int i = 0; i < n; i++) {
    //     if (fin[i]) continue;
    //     bool found = false;
    //     for (auto cur : adj[i]) {
    //         if (fin[cur]) found = true;
    //     }
    //     if (!found) assert(false);
    // }
    // assert((int)ans.size() <= n / 2);

    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld ", ans[i] + 1);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
