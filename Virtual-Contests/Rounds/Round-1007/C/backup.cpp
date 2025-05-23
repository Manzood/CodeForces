#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void dfs1(int node, int par, vector<vector<int>>& adj, vector<int>& cur,
          bool& found, int target) {
    if (node == target) found = true;
    for (auto u : adj[node]) {
        if (u == par) continue;
        dfs1(u, node, adj, cur, found, target);
    }
    cur.push_back(node);
}

void getSimplePath(int node, int par, vector<vector<int>>& adj,
                   vector<int>& cur, int target, bool& found) {
    cur.push_back(node);
    if (node == target) {
        found = true;
        return;
    }
    for (auto u : adj[node]) {
        if (u == par) continue;
        getSimplePath(u, node, adj, cur, target, found);
        if (found) return;
    }
    cur.pop_back();
}

void solve([[maybe_unused]] int test) {
    int n, st, en;
    scanf("%lld%lld%lld", &n, &st, &en);
    st--, en--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    for (auto u : adj[st]) {
        vector<int> cur;
        bool found = false;
        dfs1(u, st, adj, cur, found, en);
        if (!found) {
            for (auto x : cur) ans.push_back(x);
        }
    }

    // simple path to en
    vector<int> path;
    bool found = false;
    getSimplePath(st, -1, adj, path, en, found);
    // and the branches in between
    for (auto x : path) ans.push_back(x);
    ans.pop_back();  // remove en from it for now

    // solve en subtree
    if (en != st) {
        path.clear();
        dfs1(en, ans.back(), adj, path, found, en);
        for (auto x : path) ans.push_back(x);
    } else {
        ans.push_back(en);
    }

    // assert((int)ans.size() == n);
    for (auto x : ans) {
        printf("%lld ", x + 1);
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
