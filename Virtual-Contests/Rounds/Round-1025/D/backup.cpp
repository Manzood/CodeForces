#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int>& d, vector<int>& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) v = j;
        }

        if (d[v] == INF) break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

void solve([[maybe_unused]] int test) {
    adj.clear();
    int n, m, l;
    scanf("%lld%lld%lld", &n, &m, &l);
    vector<int> a(l);
    for (int i = 0; i < l; i++) {
        scanf("%lld", &a[i]);
    }
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    vector<int> d, p;
    dijkstra(0, d, p);

    sort(a.begin(), a.end());
    vector<int> s = a;
    for (int i = 1; i < l; i++) s[i] = a[i] + s[i - 1];
    vector<bool> hasOdd(n, false);
    for (int i = l - 1; i >= 0; i--) {
        if (a[i] & 1) hasOdd[i] = true;
        if (i < l - 1) {
            if (hasOdd[i + 1]) hasOdd[i] = true;
        }
    }

    vector<bool> ans(n, false);
    ans[0] = true;
    for (int i = 1; i < n; i++) {
        int val = d[i];
        int ind = lower_bound(s.begin(), s.end(), val) - s.begin();
        if (ind < l) {
            int tot = s[ind];
            if ((tot - val) % 2 == 0) {
                ans[i] = true;
            } else {
                if (ind < l - 1 && hasOdd[ind + 1]) ans[i] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i])
            printf("1");
        else
            printf("0");
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
