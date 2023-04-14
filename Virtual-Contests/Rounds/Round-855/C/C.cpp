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
    priority_queue<int> max_pq;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 0) {
            if ((int)max_pq.size() > 0) {
                int val = max_pq.top();
                ans += val;
                max_pq.pop();
            }
        } else {
            max_pq.push(a[i]);
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
