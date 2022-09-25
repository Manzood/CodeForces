#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, c;
    scanf("%lld%lld", &n, &c);
    vector<int> a(n);
    vector<int> cnt(101, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < 101; i++) {
        if (cnt[i] > 0) {
            ans += min(cnt[i], c);
        }
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
