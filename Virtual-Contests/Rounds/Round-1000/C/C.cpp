#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (deg[i] > deg[best]) {
            best = i;
        }
    }
    vector<int> mxDeg;
    for (int i = 0; i < n; i++) {
        if (deg[i] == deg[best]) mxDeg.push_back(i);
    }
    int f1 = mxDeg[0], f2 = -1;
    for (int i = 1; i < (int)mxDeg.size(); i++) {
        bool found = false;
        for (auto x : adj[mxDeg[i]]) {
            if (x == f1) {
                found = true;
            }
        }
        if (found) {
            if (i == 1) {
                f1 = mxDeg[1];
            } else {
                f1 = mxDeg[0];
                f2 = mxDeg[i];
                break;
            }
        } else {
            f2 = mxDeg[i];
            break;
        }
    }
    int ans2 = 0;
    if (f2 != -1) {
        ans2 = 1 + deg[f1] + deg[f2] - 2;
    }
    int ans = 1;
    ans += deg[best] - 1;
    for (auto x : adj[best]) {
        deg[x]--;
    }
    int secondBest = best == 0 ? 1 : 0;
    for (int i = 0; i < n; i++) {
        if (i == best) continue;
        if (deg[i] > deg[secondBest]) {
            secondBest = i;
        }
    }
    ans += deg[secondBest] - 1;
    printf("%lld\n", max(ans, ans2));
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
