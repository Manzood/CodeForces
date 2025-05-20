#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get(int x, int y) {
    if (x <= 1 && y <= 1) return 0;
    int ret = 0;
    if (x > 1)
        ret += 1 + get((x + 1) / 2, y);
    else
        ret = 1 + get(x, (y + 1) / 2);
    return ret;
}

void solve([[maybe_unused]] int test) {
    int n, m, a, b;
    scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
    int xrem = max(n - a, a - 1);
    int yrem = max(m - b, b - 1);
    int ans = 0;
    ans = 1 + get(n - xrem, m);
    ans = min(ans, 1 + get(n, m - yrem));
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
