#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dist = max(n - 1 - i, i);
            dist += max(m - 1 - j, j);
            ans.push_back(dist);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
