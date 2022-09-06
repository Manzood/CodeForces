#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(n);
    vector<int> mi, mx;
    int has_ascent = 0;
    vector<bool> ascent(n, false);
    for (int i = 0; i < n; i++) {
        int len;
        scanf("%lld", &len);
        a[i].resize(len);
        int cur = INF;
        int cur_mx = 0;
        bool cur_has_ascent = false;
        for (int j = 0; j < len; j++) {
            scanf("%lld", &a[i][j]);
            if (!cur_has_ascent && j > 0 && a[i][j] > cur) {
                has_ascent++;
                cur_has_ascent = true;
            }
            cur = min(cur, a[i][j]);
            cur_mx = max(cur_mx, a[i][j]);
        }
        if (!cur_has_ascent) {
            mi.push_back(cur);
            mx.push_back(cur_mx);
        }
    }
    sort(mi.begin(), mi.end());
    int ans = 0;
    for (int i = 0; i < (int)mx.size(); i++) {
        int ind = lower_bound(mi.begin(), mi.end(), mx[i]) - mi.begin();
        ans += ind;
        ans += has_ascent;
    }
    if (has_ascent) ans += has_ascent * n;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
