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
    for (int i = 0; i < n - 1; i++) {
        int cur = 0;
        if (i > 0 && a[i - 1] == a[i]) cur++;
        cur += a[i] == a[i + 1];
        if (n - i - 1 > 0 && a[n - i - 2] == a[n - i - 1]) cur++;
        cur += a[n - i - 1] == a[n - i];
        int val = 0;
        swap(a[i], a[n - i - 1]);
        if (i > 0 && a[i - 1] == a[i]) val++;
        val += a[i] == a[i + 1];
        if (n - i - 1 > 0 && a[n - i - 2] == a[n - i - 1]) val++;
        val += a[n - i - 1] == a[n - i];
        if (val > cur) swap(a[i], a[n - i - 1]);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i] == a[i + 1];
    }
    // debug(a);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
