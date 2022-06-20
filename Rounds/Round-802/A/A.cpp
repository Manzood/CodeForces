#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int s1 = 0, s2 = 0;
    int start = 1;
    for (int i = 0; i < n; i++) {
        s1 += start;
        start += m;
    }
    start -= m;
    start++;
    for (int i = 1; i < m; i++) {
        s1 += start;
        start++;
    }
    start = 1;
    for (int i = 0; i < m; i++) {
        s2 += start;
        start++;
    }
    start--;
    for (int i = 1; i < n; i++) {
        start += m;
        s2 += start;
    }
    int ans = min(s1, s2);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
