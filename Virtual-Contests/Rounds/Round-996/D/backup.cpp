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
    int cur = 1;
    float ans = a[0], pos = k;
    while (cur < n && pos < l) {
        if (a[cur] <= pos) {
            pos = min(pos + k, (float)a[cur] + ans + k);
            cur++;
            continue;
        }
        if (a[cur] - ans <= pos) {
            pos += k;
            cur++;
            continue;
        }
        float diff = (float)a[cur] - ans - pos;
        ans += diff / 2;
        pos = pos + diff / 2 + k;
        cur++;
    }
    if (pos < l) {
        ans += l - pos;
    }
    printf("%lf\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
