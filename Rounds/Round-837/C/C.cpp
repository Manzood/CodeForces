#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int prod = 1;
    bool ans = false;
    int x = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        int v = (cnt * (mod % a[i])) % a[i];
        int val =
            (((((v + x) % a[i]) * (mod % a[i])) % a[i]) + (prod % a[i])) % a[i];
        if (__gcd(val, a[i]) > 1) ans = true;
        prod *= a[i];
        x += prod / mod;
        cnt += x / mod;
        x %= mod;
        prod %= mod;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
