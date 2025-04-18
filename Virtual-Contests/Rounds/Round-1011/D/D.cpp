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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    priority_queue<int, vector<int>, greater<int> > min_pq;
    for (int i = n - 1; i >= 0; i--) {
        int sz = (n - i) / (k + 1);
        if ((int)min_pq.size() < sz) {
            min_pq.push({a[i]});
        } else if (!min_pq.empty()) {
            int cur = min_pq.top();
            if (cur < a[i]) {
                min_pq.pop();
                min_pq.push({a[i]});
            }
        }
    }
    int ans = 0;
    while (!min_pq.empty()) {
        ans += min_pq.top();
        min_pq.pop();
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
