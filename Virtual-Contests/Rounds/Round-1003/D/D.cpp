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
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
        int s1 = 0, s2 = 0;
        for (auto val : x) s1 += val;
        for (auto val : y) s2 += val;
        return s1 > s2;
    });
    int pref = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref += a[i][j];
            ans += pref;
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
