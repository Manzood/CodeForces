#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    if (!(n & 1)) {
        int cur = 0;
        for (int i = 0; i < n / 2; i++) {
            cur ^= a[i];
        }
        a.push_back(cur);
        n++;
    }

    vector<int> pref(n, 0);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] ^ a[i];

    function<int(int)> check = [&](int val) {
        if (val <= n) return a[val - 1];
        if (val / 2 <= n) return pref[val / 2 - 1];
        if ((val / 2 - n) % 2 == 0) return pref[n - 1];
        return check(val / 2) ^ pref[n - 1];
    };

    printf("%lld\n", check(l));
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
