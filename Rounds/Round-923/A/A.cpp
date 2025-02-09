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
    string s;
    cin >> s;
    int st = n, e = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            st = min(st, i);
            e = max(e, i);
        }
    }
    int ans = max(0LL, e - st + 1);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
