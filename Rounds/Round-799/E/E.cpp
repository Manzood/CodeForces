#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int inf = (int) 1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, s;
    scanf("%lld%lld", &n, &s);
    vector <int> a(n);
    vector <int> l(n + 1, inf);
    vector <int> r(n + 1, inf);
    int sum = 0;
    l[0] = 0;
    r[0] = 0;
    int ans = inf;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (sum < s) ans = -1;
    s = sum - s;
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        l[sum] = min(l[sum], i + 1);
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        r[sum] = min(r[sum], (n - i));
    }
    for (int i = 0; i <= s && ans != -1; i++) {
        if (l[i] + r[s - i] <= n) {
            ans = min(ans, l[i] + r[s - i]);
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
