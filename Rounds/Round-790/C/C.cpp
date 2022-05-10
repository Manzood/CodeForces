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
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int mi = (int) 1e9 + 7;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int cur = 0;
            for (int k = 0; k < m; k++) {
                cur += abs(s[i][k] - s[j][k]);
            }
            mi = min(mi, cur);
        }
    }
    printf("%lld\n", mi);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
