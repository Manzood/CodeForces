#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<int> a(m);
    int mx = (n + k - 1) / k;
    bool ans = true;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > mx) ans = false;
        if (a[i] == mx) cnt++;
    }
    if ((n % k != 0) && cnt > (n % k)) {
        ans = false;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
