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
    vector<int> a(n), b(n);
    int btot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (b[i] < a[i]) swap(a[i], b[i]);
        btot += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = btot;
    int cur = n - 1;
    for (int i = 0; i < k - 1; i++) {
        ans += a[cur--];
    }
    ans++;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
