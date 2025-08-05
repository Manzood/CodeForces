#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

vector<int> dijkstra(int s, vector<vector<int>>& adj, int n) {
    vector<int> d(n, INF);
    d[s] = 0;

    set<pair<int, int>> min_pq;
    min_pq.insert({d[s], s});
    while (!min_pq.empty()) {
        int node = (*min_pq.begin()).second;
        min_pq.erase(min_pq.begin());

        for (auto u : adj[node]) {
            if (d[u] > d[node] + 1) {
                if (min_pq.count({d[u], u})) min_pq.erase({d[u], u});

                d[u] = d[node] + 1;
                min_pq.insert({d[u], u});
            }
        }
    }

    return d;
}

void solve([[maybe_unused]] int test) {
    int n, s1, s2, m1, m2;
    scanf("%lld%lld%lld", &n, &s1, &s2);
    set<pair<int, int>> a, b;
    scanf("%lld", &m1);
    for (int i = 0; i < m1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        if (u > v) swap(u, v);
        a.insert({u, v});
    }
    scanf("%lld", &m2);
    for (int i = 0; i < m2; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        if (u > v) swap(u, v);
        b.insert({u, v});
    }

    vector<bool> marked(n, false);
    for (auto x : a) {
        if (b.count(x)) {
            marked[x.first] = true;
            marked[x.second] = true;
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
