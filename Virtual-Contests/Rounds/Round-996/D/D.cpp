#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k, l;
    scanf("%lld%lld%lld", &n, &k, &l);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int cur = 1, ans = 2 * a[0], pos = 2 * k;
    while (cur < n && pos < 2 * l) {
        if (2 * a[cur] <= pos) {
            pos = min(pos + 2 * k, 2 * a[cur] + ans + 2 * k);
            cur++;
            continue;
        }
        if (2 * a[cur] - ans <= pos) {
            pos += 2 * k;
            cur++;
            continue;
        }
        int diff = a[cur] - (ans + pos) / 2 - ((ans + pos) & 1);
        ans += diff;
        pos += diff + 2 * k;
        cur++;
    }
    if (pos < 2 * l) {
        ans += 2 * l - pos;
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
