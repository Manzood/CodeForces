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
    m--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    priority_queue<int> p;
    int sum = a[m];
    p.push(a[m]);
    for (int i = m - 1; i >= 0; i--) {
        while (sum > 0) {
            int val = p.top();
            p.pop();
            sum += 2 * (-val);
            p.push(-val);
            ans++;
        }
        sum += a[i];
        p.push(a[i]);
    }
    priority_queue<int, vector<int>, greater<int> > min_pq;
    sum = 0;
    for (int i = m + 1; i < n; i++) {
        sum += a[i];
        min_pq.push(a[i]);
        while (sum < 0) {
            int val = min_pq.top();
            min_pq.pop();
            sum += 2 * (-val);
            min_pq.push(-val);
            ans++;
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
