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
    vector<vector<int>> t1(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        t1[u].push_back(v);
        t1[v].push_back(u);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
