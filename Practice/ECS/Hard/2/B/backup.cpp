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

        // create simplified graph with connected components
        int cnt = 0;
        vector<bool> vis(2 * n + 1, false);
        vector<int> mapping(2 * n + 1, -1);
        for (int i = 0; i <= 2 * n; i++) {
            if (!vis[d.parent(i)]) {
                vis[d.parent(i)] = true;
                mapping[d.parent(i)] = cnt++;
            }
        }

        vector<vector<int>> graphset(cnt);
        for (int i = 0; i < 2 * n + 1; i++) {
            int f = d.parent(i);

            for (auto x : adj[i]) {
                f = d.parent(i);
                int rep = d.parent(x.first);
                f = mapping[f], rep = mapping[rep];

                if (x.second == 1) {
                    graphset[f].push_back(rep);
                    graphset[rep].push_back(f);
                }
            }
        }

        for (int i = 0; i < cnt; i++) {
            debug(cnt, graphset[i].size());
            sort(graphset[i].begin(), graphset[i].end());
        }

        vector<vector<int>> graph(cnt);
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < (int)graphset[i].size(); j++) {
                if (j > 0 && graphset[i][j] == graphset[i][j - 1]) continue;
                graph[i].push_back(graphset[i][j]);
            }
        }

        // check if simplified graph is bipartite
        bool possible = true;

        auto checkbipartite = [&]() {
            vector<int> color(cnt, -1);
            queue<int> q;
            q.push(0);
            color[0] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto u : graph[node]) {
                    if (color[u] != -1) {
                        if (color[u] == color[node]) possible = false;
                    } else {
                        color[u] = !color[node];
                        q.push(u);
                    }
                }
            }
        };
        checkbipartite();

        // count number of connected components in simplified graph
        function<void(int)> dfs = [&](int node) {
            if (vis[node]) return;
            vis[node] = true;
            for (auto u : graph[node]) dfs(u);
        };

        int ccs = 0;
        vis.assign(cnt, false);
        for (int i = 0; i < cnt; i++) {
            if (!vis[i]) {
                ccs++;
                dfs(i);
            }
        }

        int cur = 1;
        for (int i = 0; i < ccs - 1; i++) (cur *= 2) %= MOD;
        if (!possible) cur = 0;

        (ans += cur) %= MOD;
        // debug(len, cur);
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
