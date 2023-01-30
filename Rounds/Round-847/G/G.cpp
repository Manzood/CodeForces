#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = 1e18;

vector<bool> vis;
int bfs(vector<vector<int>>& adj, vector<bool>& bonus, vector<bool>& token,
        vector<int>& d) {
    queue<int> q;
    q.push(0);
    d[0] = 0;
    vis[0] = true;
    vector<bool> seen_token((int)adj.size(), false);
    int fin = -1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto u : adj[cur]) {
            if (token[u]) {
                seen_token[u] = true;
                d[u] = min(d[cur] + 1, d[u]);
                fin = u;
            }
            if (!vis[u] && bonus[u]) {
                vis[u] = true;
                q.push(u);
                d[u] = min(d[u], d[cur] + 1);
            }
        }
    }
    int cnt = 0;
    for (auto x : seen_token)
        if (x) cnt++;
    if (cnt > 1) fin = INF;
    return fin;
}

int checktokens(int token, vector<vector<int>>& adj, vector<bool>& bonus) {
    int retval = 0;
    bool found = false;
    for (auto u : adj[token]) {
        if (bonus[u]) {
            for (auto x : adj[u]) {
                if (bonus[x]) {
                    found = true;
                }
            }
            retval++;
        }
    }
    if (found) retval = INF;
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int p, b;
    scanf("%lld%lld", &p, &b);
    vector<int> t(p);
    vector<bool> token(n, false), bonus(n, false);
    for (int i = 0; i < p; i++) {
        scanf("%lld", &t[i]);
        t[i]--;
        token[t[i]] = true;
    }
    for (int i = 0; i < b; i++) {
        int x;
        scanf("%lld", &x);
        x--;
        bonus[x] = true;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // do a bfs from vertex 0 to find potential start token
    // if there are two, output yes
    // other than the potential start token, find if any other token can bounce
    // if yes, output yes
    // otherwise find sum of all other token moves
    // if lte distance, output yes
    bool ans = false;
    vis.assign(n, false);
    vector<int> d(n, INF);
    int fin = bfs(adj, bonus, token, d);
    if (fin == INF) {
        ans = true;
    } else if (fin > -1) {
        assert(fin < n);
        // check other tokens, find their sum
        int tot = 0;
        for (auto x : t) {
            if (x == fin) continue;
            int val = checktokens(x, adj, bonus);
            if (val == INF) {
                ans = true;
            } else if (val) {
                tot++;
            }
        }
        if (tot + 1 >= d[fin]) ans = true;
    }
    if (token[0]) ans = true;
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
