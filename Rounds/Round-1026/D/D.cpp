#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
    }

    bool possible = false;
    int ans = (int)1e9 + 7;

    int low = 0, high = (int)1e9 + 7;
    while (low <= high) {
        int mid = (low + high) / 2;

        vector<int> reach(n, -1);
        reach[0] = 0;
        for (int i = 0; i < n; i++) {
            if (reach[i] < 0) continue;
            int cur = min(mid, reach[i] + a[i]);

            for (auto edge : adj[i]) {
                if (edge.second <= cur) {
                    reach[edge.first] = max(reach[edge.first], cur);
                }
            }
        }

        if (reach[n - 1] >= 0) {
            possible = true;
            ans = min(ans, reach[n - 1]);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (possible) {
        printf("%lld\n", ans);
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
