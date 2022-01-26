#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(x) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, l, k;
    scanf("%lld%lld%lld", &n, &l, &k);
    vector <int> a(n), influence(n, 0);
    vector <int> limit(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &limit[i]);
    }
    a.push_back(l);
    for (int i = 0; i < n; i++) {
        influence[i] = a[i+1] - a[i];
    }
    int ans = 0;
    vector <int> pref(n+1, 0);
    vector <int> total_influence(n+1, 0);
    // for (int i = n - 1; i >= 0; i--) {
    //     total_influence[i] += influence[i];
    //     if (i < n - 1) total_influence[i] += total_influence[i+1];
    // }
    for (int i = 0; i <= n; i++) {
        if (i < n) ans += limit[i] * influence[i];
        if (i > 0) pref[i] += pref[i-1] + limit[i-1] * influence[i-1];
        if (i > 0) total_influence[i] += total_influence[i-1] + influence[i-1];
    }
    // debug (ans);
    // int dp[n+1][k+1][k+1];
    int best[n+1][k+1];
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j <= k; j++) {
            // for (int x = 0; x <= k; x++) {
            //     dp[i][j][x] = ans;
            // }
            best[i][j] = ans;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k && j < i; j++) {
            for (int x = 0; x <= k && x <= j; x++) {
                // taking x in a row
                // calculate improvement for those segments
                int val = pref[i] - pref[i-x-1];
                int new_val = limit[i-x-1] * (total_influence[i] - total_influence[i-x-1]);
                int change = new_val - val;
                // debug (i, x, val);
                // debug (i, x, new_val);
                best[i][j] = min(best[i][j], best[i-x-1][j-x] + change);
                // best[i][j] = min(best[i][j], dp[i][j][x]);
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         printf("%lld ", best[i][j]);
    //     }
    //     printf("\n");
    // }
    // for (int i = 0; i <= n; i++) {
    //     printf("i: %lld\n", i);
    //     for (int j = 0; j <= k; j++) {
    //         printf("j: %lld\n", j);
    //         for (int x = 0; x <= k; x++) {
    //             printf("%lld ", dp[i][j][x]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i <= k; i++) {
        ans = min(ans, best[n][i]);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
