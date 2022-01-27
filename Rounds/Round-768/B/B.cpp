#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int l = a[n-1];
    int sz = 1;
    int cur = sz;
    bool found = false;
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        sz = n - 1 - i;
        if (!found) {
            if (a[i] != l) {
                found = true;
                cur = sz - 1;
            }
        } else {
            cur--;
        }
        if (cur == 0) {
            found = false;
            ans++;
            cur = sz + 1;
            // debug (a, a[i]);
        }
    }
    if (found) {
        ans++;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
