#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e2 + 7;

void solve([[maybe_unused]] int test) {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] != b[i];
    }
    if (cnt & 1) {
        printf("-1\n");
        return;
    }
    if (cnt >= 4 || cnt == 0) {
        printf("%lld\n", cnt / 2 * y);
    } else if (cnt == 2) {
        // check adjacency
        bool adj = false;
        int prev = -2;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (prev == i - 1) {
                    adj = true;
                }
                prev = i;
            }
        }
        int ans = 0;
        if (adj)
            ans = min(x, 2 * y);
        else
            ans = y;
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
