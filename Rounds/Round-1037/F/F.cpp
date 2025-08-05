#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    vector<vector<pair<int, int>>> adj(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        scanf("%lld%lld%lld", &u, &v, &c);
        u--, v--;

        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        deg[u]++, deg[v]++;
    }

    vector<map<int, int>> mp(n);
    for (int i = 0; i < n; i++) {
        for (auto u : adj[i]) {
            mp[i][a[u.first]] += u.second;
        }
    }

    vector<bool> heavy(n, false);
    int sqrt = (int)sqrtl(n);
    for (int i = 0; i < n; i++) {
        if (deg[i] > sqrt) {
            heavy[i] = true;
        }
    }

    vector<vector<pair<int, int>>> heavy_neighbours(n);
    for (int i = 0; i < n; i++) {
        for (auto u : adj[i]) {
            if (heavy[u.first]) {
                heavy_neighbours[i].push_back(u);
            }
        }
    }

    int val = 0;
    for (int i = 0; i < n; i++) {
        for (auto u : adj[i]) {
            if (a[u.first] != a[i]) {
                val += u.second;
            }
        }
    }
    val /= 2;

    for (int query = 0; query < q; query++) {
        int v, x;
        scanf("%lld%lld", &v, &x);
        v--;

        int current = a[v];
        if (current == x) {
            printf("%lld\n", val);
            continue;
        }

        if (heavy[v]) {
            val += mp[v][current];
            val -= mp[v][x];

            for (auto u : heavy_neighbours[v]) {
                mp[u.first][current] -= u.second;
                mp[u.first][x] += u.second;
            }
        } else {
            for (auto u : adj[v]) {
                if (a[u.first] == current) {
                    val += u.second;
                } else if (a[u.first] == x) {
                    val -= u.second;
                }

                if (heavy[u.first]) {
                    mp[u.first][current] -= u.second;
                    mp[u.first][x] += u.second;
                }
            }
        }

        a[v] = x;

        printf("%lld\n", val);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
