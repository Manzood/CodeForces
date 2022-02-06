#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    int ans = 1;
    if (k > 0) {
        if (t != s) {
            ans = 2;
        }
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
