#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18 + 7;

int normalize(int node, vector<int>& a, vector<vector<int>>& adj) {
    if ((int)adj[node].size() == 0) {
        return a[node];
    }
    int val = INF;
    for (auto x : adj[node]) {
        val = min(normalize(x, a, adj), val);
    }
    if (val > a[node]) {
        val = a[node] + (val - a[node]) / 2;
    }
    return val;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> p(n, -1);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
        adj[p[i]].push_back(i);
    }
    int ans = a[0];
    if ((int)adj[0].size()) {
        int mi = INF;
        for (auto x : adj[0]) {
            mi = min(mi, normalize(x, a, adj));
        }
        ans += mi;
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
