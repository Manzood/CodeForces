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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int l = 0, r = n - 1;
    if ((a[l] + a[r]) % 2 == 0) {
        a[l] = a[r];
    } else {
        a[r] = a[l];
    }
    int m = n - 1;
    printf("%lld\n", m);
    if (m) printf("%lld %lld\n", l + 1, r + 1);
    for (int i = 1; i < n - 1; i++) {
        if ((a[i] & 1) == (a[0] & 1)) {
            printf("%lld %lld\n", i + 1, n);
        } else {
            printf("%lld %lld\n", 1LL, i + 1);
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
