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
    vector<int> a(n), pref(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0)
            pref[i] = min(a[i], pref[i - 1]);
        else
            pref[i] = a[i];
    }

    vector<int> suff(n);
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = max(suff[i + 1], a[i]);
    }

    string ans;
    for (int i = 0; i < n; i++) {
        bool prev = true, after = true;
        if (i > 0 && pref[i - 1] < a[i]) prev = false;
        if (i < n - 1 && suff[i + 1] > a[i]) after = false;
        if (!prev && !after) {
            ans += '0';
        } else {
            ans += '1';
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
