#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int inf = 1e18;

int answer = 0;
void bfs(vector <vector <int>>& adj, int s, int t, int test) {
    int n = adj.size();
    vector <int> visited(n, false);
    vector <int> dist(n, inf);
    queue <int> q;
    vector <int> ans(n, 0);
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int cur = q.front();
        visited[cur] = true;
        q.pop();
        for (auto u: adj[cur]) {
            if (!visited[u]) {
                dist[u] = dist[cur] + 1;
                q.push(u);
                visited[u] = true;
            }
            if (u == t && dist[cur] + 1 <= dist[u] + 1) {
                if (test == 4) {
                    debug(cur);
                }
                // answer++;
                ans[cur]++;
            }
            if (dist[u] == dist[cur]) {
                ans[cur] += ans[u];
                // ans[u]++;
                // answer += ans[u];
            }
        }
    }
}

void solve([[maybe_unused]] int test) {
    answer = 0;
    int n, m;
    scanf("%lld%lld", &n, &m);
    int s, t;
    scanf("%lld%lld", &s, &t);
    s--; t--;
    vector <vector <int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(adj, s, t, test);
    printf("%lld\n", answer);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
