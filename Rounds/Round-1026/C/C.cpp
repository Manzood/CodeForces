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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> l(n), r(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &l[i], &r[i]);
        if (a[i] == 1) cnt++;
        l[i] -= cnt;
        r[i] -= cnt;
    }

    vector<int> suffmin(n, (int)1e6);
    suffmin[n - 1] = r[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffmin[i] = min(r[i], suffmin[i + 1]);
    }

    int cur = 0;
    vector<int> out = a;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (cur > r[i]) possible = false;
        if (a[i] == -1) {
            if (cur < suffmin[i]) {
                cur++;
                out[i] = 1;
            } else {
                out[i] = 0;
            }
        }
        if (cur > suffmin[i]) possible = false;
        if (cur < l[i]) possible = false;
    }

    if (possible) {
        for (int i = 0; i < n; i++) {
            printf("%lld ", out[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
