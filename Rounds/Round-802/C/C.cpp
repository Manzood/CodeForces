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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    int lowest = a[0];
    int lowered = 0;
    for (int i = 1; i < n; i++) {
        a[i] -= lowered;
        if (a[i - 1] > a[i]) {
            lowest = a[i];
            ans += abs(a[i] - a[i - 1]);
        } else {
            lowered += abs(a[i] - a[i - 1]);
            ans += abs(a[i] - a[i - 1]);
            a[i] -= abs(a[i] - a[i - 1]);
        }
    }
    ans += abs(lowest);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
