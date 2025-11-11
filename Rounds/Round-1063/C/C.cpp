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
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

    vector<pair<int, int>> pref(n, {1, 2 * n}), suff(n, {1, 2 * n});
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pref[i] = {a[0][i], a[0][i]};
        } else {
            int l = min(pref[i - 1].first, a[0][i]);
            int r = max(pref[i - 1].second, a[0][i]);
            pref[i] = {l, r};
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suff[i] = {a[1][i], a[1][i]};
        } else {
            int l = min(suff[i + 1].first, a[1][i]);
            int r = max(suff[i + 1].second, a[1][i]);
            suff[i] = {l, r};
        }
    }

    vector<int> best(2 * n + 1, 2 * n + 1);
    for (int i = 0; i < n; i++) {
        int curl = min(pref[i].first, suff[i].first);
        int curr = max(pref[i].second, suff[i].second);
        best[curl] = min(best[curl], curr);
    }

    int ans = 0;
    for (int i = 2 * n; i > 0; i--) {
        if (i < 2 * n) best[i] = min(best[i], best[i + 1]);
        if (best[i] <= 2 * n) {
            ans += 2 * n - best[i] + 1;
        }
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
