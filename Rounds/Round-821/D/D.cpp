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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] != b[i];
    }
    if (cnt & 1) {
        printf("-1\n");
        return;
    }
    int cur = 0;
    vector<bool> marked(n, false);
    int ans = 0;
    int adj = 0;
    for (int i = 0; i < n; i++) {
        if (marked[i]) continue;
        if (i < n - 1) {
            if (a[i] != b[i] && a[i + 1] != b[i + 1]) {
                marked[i] = true;
                // swap them together
                adj++;
                ans += x;
                marked[i + 1] = true;
                continue;
            }
        }
        if (a[i] != b[i]) {
            cur++;
            if (cur == 2) {
                // change them together
                ans += y;
                cur = 0;
            }
        }
    }
    ans = min(ans, (adj * 2 * y) + ((cnt - adj) / 2) * y);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
