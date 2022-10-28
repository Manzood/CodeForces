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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ans += a[i];
    }
    vector<int> b(n);
    int mx = -1;
    int ind = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (mx < b[i]) {
            mx = b[i];
            ind = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == ind) continue;
        ans += b[i];
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}