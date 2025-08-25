#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;

class dsu {
   public:
    vector<int> p, size;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.resize(n, 1);
    }
    int parent(int x) {
        // path compression
        if (x == p[x])
            return x;
        else
            return p[x] = parent(p[x]);
    }
    inline bool unite(int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x != y) {
            if (size[x] > size[y]) swap(x, y);
            p[x] = y;
            size[y] += size[x];
            return true;
        }
        return false;
    }
};

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = (int)s.size();

    vector<vector<pair<int, int>>> adj;
    auto add_edge = [&](int node, int other, int type) {
        // type 0: same. 1: different
        adj[node].push_back({other, type});
        adj[other].push_back({node, type});
    };

    int ans = 0;
    for (int len = 1; len < n; len++) {
        adj.clear();
        adj.resize(2 * n + 1);

        add_edge(2 * n - 1, 2 * n, 0);
        add_edge(len - 1, 2 * n, 0);
        for (int i = n - 1; i >= len; i--) add_edge(i, 2 * n, 1);

        for (int i = len - 1; i > len - 1 - i; i--) add_edge(i, len - 1 - i, 0);
        for (int i = n; i < 3 * n - i - 1; i++) add_edge(i, 3 * n - i - 1, 0);

        for (int i = 0; i < n; i++) {
            int ind = n - i - 1;
            if (s[i] == '0') {
                add_edge(ind, ind + n, 0);
            } else if (s[i] == '1') {
                add_edge(ind, ind + n, 1);
            }
        }

        dsu d(2 * n + 1);
        for (int i = 0; i < 2 * n + 1; i++)
            for (auto x : adj[i])
                if (x.second == 0) d.unite(x.first, i);

        // check if graph is bipartite
        bool possible = true;
        auto checkbipartite = [&]() {
            vector<int> color(2 * n + 1, -1);
            queue<int> q;
            q.push(0);
            color[0] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto u : adj[node]) {
                    if (color[u.first] != -1) {
                        if (u.second == 0) {
                            if (color[u.first] != color[node]) possible = false;
                        } else {
                            if (color[u.first] == color[node]) possible = false;
                        }
                    } else {
                        if (u.second == 1)
                            color[u.first] = !color[node];
                        else
                            color[u.first] = color[node];
                        q.push(u.first);
                    }
                }
            }
        };
        checkbipartite();

        // count number of connected components
        vector<bool> vis(2 * n + 1, false);
        function<void(int)> dfs = [&](int node) {
            if (vis[node]) return;
            vis[node] = true;
            for (auto u : adj[node]) dfs(u.first);
        };

        int ccs = 0;
        for (int i = 0; i < 2 * n + 1; i++) {
            if (!vis[i]) {
                ccs++;
                dfs(i);
            }
        }

        int cur = 1;
        for (int i = 0; i < ccs - 1; i++) (cur *= 2) %= MOD;
        if (!possible) cur = 0;

        (ans += cur) %= MOD;
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
