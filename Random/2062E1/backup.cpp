#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& a,
         vector<bool>& has, int largest) {
    if (a[node] == largest) has[node] = true;

    for (auto u : adj[node]) {
        if (u == par) continue;
        dfs(u, node, adj, a, has, largest);
        if (has[u]) has[node] = true;
    }
}

int dfs2(int node, int par, vector<vector<int>>& adj, vector<int>& a,
         vector<bool>& has) {
    assert(has[node]);

    int ret = -1;
    if (par != -1 && a[node] < a[par]) {
        return node;
    }

    for (auto u : adj[node]) {
        if (u == par) continue;
        ret = dfs2(u, node, adj, a, has);
    }
    return ret;
}

// void check(vector<vector<int>>& adj, vector<int>& a, int deleted) {
//     // do another dfs
//     int n = (int)adj.size();
//     vector<bool> visited(n, false);
//     vector<int> available;

//     function<void(int)> dfs = [&](int node) {
//         visited[node] = true;
//         if (node == deleted) return;
//         available.push_back(node);
//         for (auto u : adj[node]) {
//             if (!visited[u]) {
//                 dfs(u);
//             }
//         }
//     };
// }

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int largest = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        largest = max(largest, a[i]);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> has(n, false);
    dfs(0, -1, adj, a, has, largest);

    int x = -1, val = 0;
    for (int i = 0; i < n; i++) {
        if (!has[i]) {
            if (a[i] > val) {
                val = a[i];
                x = i;
            }
        }
    }
    if (x == -1) {
        x = dfs2(0, -1, adj, a, has);
    }

    printf("%lld\n", a[x] == largest ? 0LL : x + 1);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
