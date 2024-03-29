#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int inf = 1e18;

int bfs (int node, int t, vector <vector <int>>& adj, vector <int>& distance, set <int>& surroundings) {
    int retval = 0;
    int n = adj.size();
    queue <int> q;
    q.push(node);
    distance[node] = 0;
    vector <bool> visited(n, false);
    distance[t] = inf;
    while (!q.empty()) {
        int cur = q.front();
        if (distance[cur] > distance[t]) break;
        q.pop();
        for (auto u: adj[cur]) {
            distance[u] = min(distance[u], distance[cur] + 1);
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
            if (u == t) {
                retval++;
            }
        }
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int s, t;
    scanf("%lld%lld", &s, &t);
    vector <vector <int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set <int> surroundings;
    for (auto x: adj[t]) surroundings.insert(x);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
