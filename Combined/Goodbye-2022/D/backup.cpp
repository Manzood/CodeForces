#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

vector<bool> visited, visiting;
vector<bool> is_part;
vector<int> par;

int cnt = 0;

void mark_cycle(int node, int target) {
    is_part[node] = true;
    cnt++;
    int last = node;
    while (last != target) {
        last = par[last];
        is_part[last] = true;
    }
}

void dfs(int node, int p, vector<vector<int>>& adj) {
    if (visited[node]) return;
    visited[node] = true;
    visiting[node] = true;
    par[node] = p;
    for (auto u : adj[node]) {
        if (visiting[u] && u != p) {
            mark_cycle(node, u);
        } else {
            dfs(u, node, adj);
        }
    }
    visiting[node] = false;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    visited.assign(n, false);
    visiting.assign(n, false);
    is_part.assign(n, false);
    par.assign(n, -1);
    cnt = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        b[i]--;
    }
    vector<vector<int>> adj(n);
    vector<bool> same(n, false);
    // set<pair<int, int>> rep;
    vector<set<int>> rep(n);
    for (int i = 0; i < n; i++) {
        int f = min(a[i], b[i]);
        int s = min(a[i], b[i]);
        if (rep[f].count(s)) {
            is_part[a[i]] = true;
            is_part[b[i]] = true;
            cnt++;
        } else {
            if (a[i] == b[i]) {
                same[a[i]] = true;
            } else {
                // add edge
                adj[a[i]].push_back(b[i]);
                adj[b[i]].push_back(a[i]);
            }
        }
        rep[f].insert(s);
    }
    // detect cycles
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj);
        }
    }
    int ans = 1;
    // check for zero
    vector<bool> found(n, false);
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            found[a[i]] = true;
        } else if (is_part[a[i]] && is_part[b[i]]) {
            found[a[i]] = true;
            found[b[i]] = true;
        } else {
            if (is_part[a[i]]) {
                found[b[i]] = true;
            } else if (is_part[b[i]]) {
                found[a[i]] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!found[i]) ans = 0;
    }
    // calculate final answer
    for (int i = 0; i < n; i++) {
        if (same[i]) {
            ans *= n;
            ans %= mod;
        }
    }
    for (int i = 0; i < cnt; i++) {
        ans *= 2;
        ans %= mod;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
