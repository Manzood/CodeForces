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
    for (int i = 1; i < n / 2; i++) {
        if (a[i] == a[i - 1] || a[n - i - 1] == a[n - i]) {
            swap(a[i], a[n - i - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += a[i] == a[i - 1];
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
