#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int mod = 998244353;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    if (n & 1) {
        printf("0\n");
        return;
    }
    int ans = 1;
    for (int i = 1; i <= n / 2; i++) {
        ans *= i;
        ans %= mod;
    }
    ans *= ans;
    ans %= mod;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
