#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n, m, r, c;
    scanf("%lld%lld%lld%lld", &n, &m, &r, &c);
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool possible = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') possible = true;
        }
    }
    int ans = -1;
    if (possible) {
        ans = 2;
        for (int i = 0; i < n; i++) {
            if (a[i][c-1] == 'B') {
                ans = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (a[r-1][i] == 'B') {
                ans = 1;
            }
        }
        if (a[r-1][c-1] == 'B') {
            ans = 0;
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
