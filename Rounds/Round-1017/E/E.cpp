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
    vector<int> cnt(32, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1LL << j)) {
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1LL << j)) {
                cur += (1LL << j) * (n - cnt[j]);
            } else {
                cur += (1LL << j) * cnt[j];
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
