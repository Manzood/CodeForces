#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    l--, r--;
    vector<int> x, y, z;
    for (int i = 0; i < l; i++) {
        x.push_back(a[i]);
    }
    for (int i = l; i <= r; i++) {
        y.push_back(a[i]);
    }
    for (int i = r + 1; i < n; i++) {
        z.push_back(a[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    reverse(y.begin(), y.end());
    sort(z.begin(), z.end());
    vector<int> cpy = y;
    for (int i = 0; i < (int)y.size(); i++) {
        if (i >= (int)x.size() || y[i] <= x[i]) break;
        swap(y[i], x[i]);
    }
    int ans = 0;
    for (int i = 0; i < (int)y.size(); i++) {
        ans += y[i];
    }
    y = cpy;
    for (int i = 0; i < (int)y.size(); i++) {
        if (i >= (int)z.size() || y[i] <= z[i]) break;
        swap(y[i], z[i]);
    }
    int ans2 = 0;
    for (int i = 0; i < (int)y.size(); i++) {
        ans2 += y[i];
    }
    printf("%lld\n", min(ans, ans2));
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
