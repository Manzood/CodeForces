#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int mod = 998244353;

template <typename T>
T getpow(T a, T b, T m) {
    T result = 1;
    while (b) {
        if (b % 2 == 1) result = result * a % m;
        a = a * a % m;
        b /= 2;
    }
    return result;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int leftover = 0, tot = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int val = getpow(2LL, i, mod);
        leftover = (((val * a[i]) % mod) - tot) % mod;
        if (leftover < 0) leftover += mod;
        (ans += ans + leftover) %= mod;
        (tot += leftover) %= mod;
        debug(ans, leftover, tot);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
