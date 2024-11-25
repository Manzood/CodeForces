#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

// void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& exp,
//          vector<int>& cnt) {
//     int branches = (int)adj.size();
//     int total_count = 0;
//     for (auto u : adj[node]) {
//         if (u == par) continue;
//         dfs(u, node, adj, exp, cnt);
//         (total_count += cnt[u]) %= MOD;
//     }
//     cnt[node] = (1 + total_count) % MOD;
//     for (auto u : adj[node]) {
//         if (u == par) continue;
//         int diff = total_count - cnt[u];
//         if (diff < 0) diff += MOD;
//         (exp[node] +=
//          (exp[u] + (cnt[u] + (cnt[u] * diff) % MOD) % MOD) % MOD) %= MOD;
//     }
// }

void dfs1(int node, int parent, int depth, vector<int>& ans, vector<int>& dp,
          vector<vector<int>>& adj) {
    (ans[0] += depth) %= MOD;
    dp[node] = 1;
    for (int i : adj[node])
        if (i != parent) {
            dfs1(i, node, depth + 1, ans, dp, adj);
            (dp[node] += dp[i]) %= MOD;
        }
}

void dfs2(int node, int par, vector<int>& ans, vector<int>& dp,
          vector<vector<int>>& adj) {
    int n = (int)adj.size();
    for (int u : adj[node])
        if (u != par) {
            ans[u] = (ans[node] + n - 2 * dp[u]) % MOD;
            if (ans[u] < 0) ans[u] += MOD;
            dfs2(u, node, ans, dp, adj);
        }
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (k & 1) {
        printf("1\n");
        return;
    }
    vector<int> ans(n, 0), dp(n, 0);
    dfs1(0, -1, 0, ans, dp, adj);
    dfs2(0, -1, ans, dp, adj);
    int s = 0;
    for (auto x : ans) (s += (x + (n - 1)) % MOD) %= MOD;
    (s *= inv(2, MOD)) %= MOD;
    int cnt = n * (n - 1) / 2;
    cnt %= MOD;
    printf("%lld\n", (s * inv(cnt, MOD)) % MOD);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
