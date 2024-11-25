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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    bool ans = true;
    vector<vector<bool>> contains(k + 1, vector<bool>(2, false));
    for (int i = 0; i < n; i++) {
        if (a[i] <= k) contains[a[i]][0] = true;
    }
    for (int i = 0; i < m; i++) {
        if (b[i] <= k) contains[b[i]][1] = true;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= k; i++) {
        if (contains[i][0] && !contains[i][1])
            cnt1++;
        else if (!contains[i][0] && contains[i][1])
            cnt2++;
        else if (!contains[i][0] && !contains[i][1])
            ans = false;
    }
    if (!(cnt1 <= k / 2 && cnt2 <= k / 2)) ans = false;
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
