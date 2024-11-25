#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    int ans = m - (a[0] * min(mp[a[0]], m / a[0]));
    for (int i = 1; i < n; i++) {
        ans = min(ans, m - (a[i] * min(mp[a[i]], m / a[i])));
        if (a[i] == a[i - 1] + 1) {
            for (int j = 0; j <= mp[a[i]]; j++) {
                int cur = a[i] * min(j, m / a[i]);
                int rem = m - cur;
                cur += a[i - 1] * min(mp[a[i - 1]], rem / a[i - 1]);
                ans = min(ans, m - cur);
            }
        }
    }
    ans = m - ans;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
