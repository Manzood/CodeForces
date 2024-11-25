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
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] <= n) cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (j * j == i)
                    cur += cnt[j];
                else {
                    cur += cnt[i / j];
                    cur += cnt[j];
                }
            }
        }
        ans = max(ans, cur);
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
