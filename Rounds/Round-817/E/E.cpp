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
    vector<vector<int>> a(n);
    vector<vector<int>> tot(1002, vector<int>(1002, 0));
    vector<vector<int>> val(1002, vector<int>(1002, 0));
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        a[i] = {x, y};
        val[x][y] += x * y;
    }
    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j <= i; j++) {
            tot[i][j] = tot[i - 1][j] + tot[i][j - 1] - tot[i - 1][j - 1];
            tot[j][i] = tot[j - 1][i] + tot[j][i - 1] - tot[j - 1][i - 1];
            tot[i][j] += val[i - 1][j - 1];
            tot[j][i] += val[j - 1][i - 1];
        }
        tot[i][i] -= val[i - 1][i - 1];
    }
    // for (int i = 0; i <= 6; i++) {
    //     for (int j = 0; j <= 6; j++) {
    //         printf("%lld ", tot[i][j]);
    //     }
    //     printf("\n");
    // }
    // if (test == 2) debug(tot[6][6]);
    for (int i = 0; i < q; i++) {
        int hs, ws, hb, wb;
        scanf("%lld%lld%lld%lld", &hs, &ws, &hb, &wb);
        // int ans = max(tot[hb][wb] - tot[hs + 1][ws + 1], 0LL);
        int ans = tot[hb][wb] - tot[hs + 1][wb] - tot[hb][ws + 1] +
                  tot[hs + 1][ws + 1];
        ans = max(ans, 0LL);
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
