#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    int odd = (k & 1) ? k : k - 1;
    int even = odd < k ? k : k - 1;
    int ans = 0;
    if (n & 1) {
        n -= odd;
        ans++;
    }
    ans += (n + even - 1) / even;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
