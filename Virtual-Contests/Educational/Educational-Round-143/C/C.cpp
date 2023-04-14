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
    vector<int> a(n), b(n);
    vector<int> pref(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        pref[i] += b[i];
        if (i > 0) pref[i] += pref[i - 1];
    }
    vector<int> full(n, 0), partial(n, 0);
    for (int i = 0; i < n; i++) {
        int val = i > 0 ? pref[i - 1] : 0LL;
        int ind =
            lower_bound(pref.begin(), pref.end(), a[i] + val) - pref.begin();
        if (ind > 0) val = pref[ind - 1];
        if (i > 0) val -= pref[i - 1];
        if (ind < n) partial[ind] += a[i] - val;
        if (ind > 0) full[ind - 1]++;
        if (i > 0) full[i - 1]--;
    }
    for (int i = n - 2; i >= 0; i--) full[i] += full[i + 1];
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        ans[i] = full[i] * b[i] + partial[i];
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
