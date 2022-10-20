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
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnta += a[i] == 1;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        cntb += b[i] == 1;
    }
    int ans = abs(cnta - cntb) + 1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cur++;
        }
    }
    ans = min(ans, cur);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
