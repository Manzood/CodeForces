#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> x(n), t(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &t[i]);
        mx = max(mx, t[i]);
    }
    vector<int> leftmost(n, INF), rightmost(n, -INF);
    int left = -INF, right = INF;
    for (int i = 0; i < n; i++) {
        leftmost[i] = x[i] - (mx - t[i]);
        rightmost[i] = x[i] + (mx - t[i]);
        right = min(right, rightmost[i]);
        left = max(left, leftmost[i]);
    }
    if (right > left) {
        // pick the spot with time = mx
        printf("%lld\n", left);
        return;
    } else {
        float ans = (float)(left + right) / 2.0f;
        printf("%lf\n", ans);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
