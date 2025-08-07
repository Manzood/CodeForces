#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;
constexpr int N = (int)4e6;

vector<int> fact(N);
void precompute() {
    fact[0] = 1, fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& deg,
         int& ans) {
    int cnt = 0;
    for (auto u : adj[node]) {
        if (u == par) continue;
        if (deg[u] == 1) cnt++;
    }
    (ans *= fact[cnt]) %= mod;

    if (par == -1) {
        if (cnt != deg[node]) {
            (ans *= 2) %= mod;
        }
    }

    for (auto u : adj[node]) {
        if (u == par) continue;
        dfs(u, node, adj, deg, ans);
    }
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    if (m != n - 1) {
        printf("0\n");
        return;
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (auto u : adj[i]) {
            if (deg[u] > 1) {
                cnt++;
            }
        }

        if (cnt > 2) {
            printf("0\n");
            return;
        } else if (cnt == 2) {
            if (root == -1) {
                root = i;
            }
        }
    }

    if (root == -1) {
        root = 0;
        for (int i = 1; i < n; i++) {
            if (deg[i] > deg[root]) root = i;
        }
    }

    int ans = 1;
    if (deg[root] > 1) dfs(root, -1, adj, deg, ans);
    (ans *= 2) %= mod;

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
