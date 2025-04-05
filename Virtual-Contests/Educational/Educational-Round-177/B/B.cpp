#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k, x;
    scanf("%lld%lld%lld", &n, &k, &x);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (x > k * sum) {
        printf("0\n");
        return;
    }
    int cnt = x / sum;
    x %= sum;
    if (x == 0) {
        printf("%lld\n", (k - cnt) * n + 1);
        return;
    }
    int l = n - 1;
    int cur = a[l];
    while (cur < x) {
        cur += a[--l];
    }
    int ans = (k - cnt - 1) * n + l + 1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
