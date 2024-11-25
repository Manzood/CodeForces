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
    vector<bool> marked(m, false);
    int l = 0, r = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > 0) {
            marked[a[i] - 1] = true;
            s.insert(a[i] - 1);
        } else if (a[i] == -1) {
            l++;
        } else {
            r++;
        }
    }
    vector<int> left(m, 0), right(m, 0);
    for (int i = 1; i < m; i++) {
        if (marked[i - 1] == false) left[i]++;
        left[i] += left[i - 1];
    }
    for (int i = m - 2; i >= 0; i--) {
        if (marked[i + 1] == false) right[i]++;
        right[i] += right[i + 1];
    }
    int ans = min(m, l);
    ans = max(ans, min(m, r));
    for (int i = 0; i < m; i++) {
        int cur = (int)s.size();
        if (marked[i]) {
            cur += min(left[i], l) + min(right[i], r);
            cur = max(cur, (int)s.size() + min(left[i] + right[i], l));
            cur = max(cur, (int)s.size() + min(left[i] + right[i], r));
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
