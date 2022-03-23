#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int inf = (int) 1e18;

void solve([[maybe_unused]] int test) {
    int n, C;
    scanf("%lld%lld", &n, &C);
    vector <int> c(n), d(n), h(n);
    vector <vector <int>> prod;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &c[i], &d[i], &h[i]);
        prod.push_back({h[i] * d[i], c[i]});
    }
    vector <int> temp(C + 1, 0);
    for (int i = 0; i < n; i++) {
        temp[c[i]] = max(temp[c[i]], d[i] * h[i]);
    }
    // debug(temp);
    vector <int> dp(C + 1, 0);
    for (int i = 1; i <= C; i++) {
        // if (temp[i] > 0) {
            for (int j = 1; i * j <= C; j++) {
                dp[i * j] = max(dp[i * j], temp[i] * j);
            }
        // }
    }
    for (int i = 1; i <= C; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
    }
    int m;
    scanf("%lld", &m);
    vector <int> D(m), H(m);
    vector <int> ans(m, -1);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &D[i], &H[i]);
        int val = D[i] * H[i];
        int ind = upper_bound(dp.begin(), dp.end(), val) - dp.begin();
        if (ind != C + 1) {
            ans[i] = ind;
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%lld%c", ans[i], " \n"[i == m - 1]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
