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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++) {
        int ind = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]) - b.begin();
        if (ind < m) {
            if (a[i] >= a[i - 1])
                a[i] = min(a[i], b[ind] - a[i]);
            else
                a[i] = b[ind] - a[i];
        }
    }
    if (is_sorted(a.begin(), a.end())) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
