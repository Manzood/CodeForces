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
    vector<int> a(n);
    vector<string> s(n);
    int f = (int)1e9, se = (int)1e9, both = (int)1e9;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cin >> s[i];
        if (s[i][0] == '1' && s[i][1] == '1') {
            both = min(both, a[i]);
        } else if (s[i][0] == '1') {
            f = min(f, a[i]);
        } else if (s[i][1] == '1') {
            se = min(se, a[i]);
        }
    }
    int ans = min(both, f + se);
    if (ans == (int)1e9) ans = -1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
