#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int l = max(n - m, 0LL);
    int r = n + m;
    int range = r - l + 1;
    int ans = n;
    for (int i = 0; i < 60; i++) {
        int val = (1LL << i);
        if (val & n) continue;
        if ((val & l) || (val & r)) {
            ans += val;
            continue;
        }
        int cur = l - ((l >> i) << i);
        if (cur + range - 1 >= val) ans += val;
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
