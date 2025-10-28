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
    vector<int> occ(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        occ[a[i]]++;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        pref[i] += occ[i];
    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        int val = 0;
        for (int j = i; j < 4 * i + 1 && j <= n; j += i) {
            val += occ[j];
        }
        if (4 * i < n) val += pref[n] - pref[4 * i];
        if (n - val <= k) ans = i;
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
