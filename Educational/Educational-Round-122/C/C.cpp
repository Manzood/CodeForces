#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int c[2];
    int m[2];
    scanf("%lld%lld%lld%lld", &c[0], &c[1], &m[0], &m[1]);
    int k, w, a;
    scanf("%lld%lld%lld", &k, &w, &a);
    int val = w * k + c[1];
    bool possible = false;
    for (int i = 0; i <= k; i++) {
        int cmoves = m[0] / val;
        if (m[0] % val) cmoves++;
        int mmoves = c[0] / m[1];
        if (c[0] % m[1]) mmoves++;
        if (cmoves <= mmoves) {
            possible = true;
            break;
        }
        val -= w;
        c[0] += a;
    }
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
