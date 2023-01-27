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
    vector<int> a(n), c(m);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &c[i]);
    }
    priority_queue<int> max_pq;
    for (auto x : cnt) {
        if (x) max_pq.push(x);
    }
    sort(c.rbegin(), c.rend());
    int ans = 0;
    for (int i = 0; i < m && (int)max_pq.size() > 0; i++) {
        int mx = max_pq.top();
        max_pq.pop();
        ans += min(c[i], mx);
        mx -= c[i];
        if (mx > 0) max_pq.push(mx);
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
