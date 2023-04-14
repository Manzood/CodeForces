#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r, k;
        scanf("%lld%lld%lld", &l, &r, &k);
        l--;
        r--;
        int sum = pref[n];
        int val = pref[r + 1] - pref[l];
        sum -= val;
        sum += (r - l + 1) * k;
        printf(sum & 1 ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
