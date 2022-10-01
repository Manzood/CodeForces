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
    int fire = 0, frost = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 0)
            fire++;
        else
            frost++;
    }
    vector<int> s, t;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (a[i] == 0) {
            s.push_back(b[i]);
        } else {
            t.push_back(b[i]);
        }
        ans += b[i];
    }
    int inc = 0;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int l1 = 0;
    for (int i = (int)t.size() - 1; i >= 0 && i >= (int)t.size() - fire; i--) {
        inc += t[i];
        l1 = t[i];
    }
    int l2 = 0;
    for (int i = (int)s.size() - 1; i >= 0 && i >= (int)s.size() - frost; i--) {
        inc += s[i];
        l2 = s[i];
    }
    if (t.size() == s.size()) {
        ans -= min(l1, l2);
    }
    ans += inc;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
