#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> k(n), h(n);
    vector <vector <int>> a;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &k[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &h[i]);
        a.push_back  ({k[i] - h[i], h[i]});
    }
    sort (a.begin(), a.end());
    int endpoint = -1;
    int len = 0;
    int ans = 0;
    int startpoint = -1;
    for (int i = 0; i < n; i++) {
        if (endpoint <= a[i][0]) {
            // debug (n, startpoint, len);
            ans += (len * (len + 1)) / 2;
            len = 0;
            startpoint = -1;
        }
        if (startpoint == -1) {
            startpoint = a[i][0];
        }
        endpoint = max (endpoint, a[i][0] + a[i][1]);
        len = max (len, a[i][0] + a[i][1] - startpoint);
    }
    ans += (len * (len + 1)) / 2;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
