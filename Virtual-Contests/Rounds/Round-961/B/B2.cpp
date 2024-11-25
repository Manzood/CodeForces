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
    vector<int> a(n), b(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        // mp[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        mp[a[i]] = b[i];
    }
    sort(a.begin(), a.end());
    int ans = m - (a[0] * min(mp[a[0]], m / a[0]));
    for (int i = 1; i < n; i++) {
        ans = min(ans, m - (a[i] * min(mp[a[i]], m / a[i])));
        if (a[i] == a[i - 1] + 1) {
            int cur_used = min(mp[a[i]], m / a[i]);
            int cur = a[i] * cur_used;
            int rem = m - cur;
            int used = min(mp[a[i - 1]], rem / a[i - 1]);
            cur += a[i - 1] * used;
            ans = min(ans, m - cur);
            if (mp[a[i]]) {
                // try replacing it with a[i] - 1
                if (mp[a[i - 1]] - used > 0 &&
                    mp[a[i - 1]] - used >= a[i] - (m - cur) &&
                    cur_used >= a[i] - (m - cur)) {
                    ans = 0;
                }
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
