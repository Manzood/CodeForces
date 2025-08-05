#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    bool ans = true;
    if (a[0] % b[0] != 0 || b[n - 1] % a[n - 1] != 0) ans = false;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] % a[i] != 0) {
            ans = false;
        }
        int val = a[i - 1] / a[i];
        int x = gcd(a[i], b[i]);
        if (gcd(b[i] / x, val) > 1) {
            ans = false;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (b[i + 1] % b[i] != 0) {
            ans = false;
        }
        int val = b[i + 1] / b[i];
        int x = gcd(a[i], b[i]);
        if (gcd(a[i] / x, val) > 1) {
            ans = false;
        }
    }

    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
