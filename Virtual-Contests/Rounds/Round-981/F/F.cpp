#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    n %= MOD;
    if (k == 1) {
        printf("%lld\n", n);
        return;
    }
    int prev = 0, current = 1;
    int len = 0;
    for (int i = 0; i < 10 * k; i++) {
        int temp = (current + prev) % k;
        prev = current;
        current = temp;
        if (temp == 0) {
            len = i + 2;
            break;
        }
    }
    int ans = (n * len) % MOD;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
