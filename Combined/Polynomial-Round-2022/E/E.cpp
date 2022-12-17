#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int LOG = 25;

// int lca(int a, int b, vector<vector<int>>& lift, vector<int>& depth) {
//     if (depth[b] > depth[a]) swap(a, b);
//     int val = depth[a] - depth[b];
//     int cur = a;
//     for (int i = 0; i < LOG && cur != -1; i++) {
//         if ((1LL << i) & val) {
//             if (cur != -1) cur = lift[cur][i];
//         }
//     }
//     // assert(depth[cur] == depth[b]);
//     int ans = -1;
//     if (cur == b) {
//         ans = b;
//     } else {
//         int other = b;
//         for (int i = LOG - 1; i >= 0; i--) {
//             if (lift[cur][i] != lift[other][i]) {
//                 cur = lift[cur][i];
//                 other = lift[other][i];
//             } else {
//                 ans = lift[cur][i];
//             }
//         }
//     }
//     return ans;
// }

vector<bool> visited;
void dfs(int node, int p, int d, vector<int>& depth, vector<vector<int>>& adj,
         vector<int>& par) {
    if (visited[node]) return;
    par[node] = p;
    depth[node] = d;
    visited[node] = true;
    for (auto u : adj[node]) {
        dfs(u, node, d + 1, depth, adj, par);
    }
}

bool filltree(int node, int par, int type, vector<vector<int>>& adj,
              vector<vector<bool>>& need) {
    bool retval = false;
    retval |= need[type][node];
    for (auto u : adj[node]) {
        if (u != par) {
            retval |= filltree(u, node, type, adj, need);
        }
    }
    need[type][node] = need[type][node] | retval;
    return retval;
}

void dfs2(int node, int type, int lim, vector<vector<int>>& adj,
          vector<vector<int>>& lift, vector<vector<bool>>& need) {
    if (visited[node]) return;
    visited[node] = true;
    if (need[type][node]) {
        int other = node;
        for (int i = 0; i < LOG; i++) {
            if (other == -1) break;
            if ((1LL << i) & lim) {
                other = lift[other][i];
            }
        }
        if (other != -1) {
            need[!type][other] = true;
        }
    }
    for (auto u : adj[node]) {
        dfs2(u, type, lim, adj, lift, need);
    }
}

bool calculate(int node, int type, int par, vector<vector<int>>& adj,
               vector<vector<bool>>& need, int& ans) {
    bool retval = false;
    retval |= need[type][node];
    int cnt = 0;
    for (auto u : adj[node]) {
        if (u != par) {
            bool tmp = calculate(u, type, node, adj, need, ans);
            if (tmp) cnt++;
            retval |= tmp;
        }
    }
    ans += 2 * cnt;
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, d;
    scanf("%lld%lld", &n, &d);
    vector<vector<int>> adj(n);
    vector<vector<bool>> need(2, vector<bool>(n, false));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m1, m2;
    scanf("%lld", &m1);
    for (int i = 0; i < m1; i++) {
        int val;
        scanf("%lld", &val);
        need[0][val - 1] = true;
    }
    scanf("%lld", &m2);
    for (int i = 0; i < m2; i++) {
        int val;
        scanf("%lld", &val);
        need[1][val - 1] = true;
    }
    visited.assign(n, false);
    vector<int> par(n);
    vector<int> depth(n, 0);
    dfs(0, -1, 0, depth, adj, par);
    vector<vector<int>> lift(n, vector<int>(LOG, -1));
    for (int i = 0; i < n; i++) {
        lift[i][0] = par[i];
    }
    for (int exp = 1; exp < LOG; exp++) {
        for (int i = 0; i < n; i++) {
            if (lift[i][exp - 1] != -1) {
                lift[i][exp] = lift[lift[i][exp - 1]][exp - 1];
            }
        }
    }
    filltree(0, -1, 0, adj, need);
    filltree(0, -1, 1, adj, need);
    visited.assign(n, false);
    dfs2(0, 0, d, adj, lift, need);
    visited.assign(n, false);
    dfs2(0, 1, d, adj, lift, need);
    filltree(0, -1, 0, adj, need);
    filltree(0, -1, 1, adj, need);
    int ans = 0;
    calculate(0, 0, -1, adj, need, ans);
    calculate(0, 1, -1, adj, need, ans);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
