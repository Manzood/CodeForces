#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int inf = (int) 1e18;

void solve([[maybe_unused]] int test) {
    int n, C;
    scanf("%lld%lld", &n, &C);
    vector <int> c, d, h;
    vector <vector <int>> prod;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &c[i], &d[i], &h[i]);
        prod.push_back({h[i] * d[i], c[i]});
    }
    sort (prod.begin(), prod.end());
    vector <int> min_suff(n, inf);
    for (int i = n - 1; i >= 0; i--) {
        min_suff[i] = min(prod[i][1], min_suff[i]);
    }
    int m;
    scanf("%lld", &m);
    vector <int> D, H;
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &D[i], &H[i]);
    }
    vector <int> ans(m, -1);
    for (int i = 0; i < n; i++) {
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
