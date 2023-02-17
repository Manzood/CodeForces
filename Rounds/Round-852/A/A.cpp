#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    int n, m;
    scanf("%lld%lld", &n, &m);
    int v1 = a * m;
    int v2 = b * (m + 1);
    int cnt = n / (m + 1);
    int ans = cnt * min(v1, v2);
    ans += (n % (m + 1)) * min(a, b);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
