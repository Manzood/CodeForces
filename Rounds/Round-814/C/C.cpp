#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int inf = (int)1e18 + 7;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    vector<int> wins(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int winner = max(a[0], a[1]);
    wins[winner]++;
    for (int i = 2; i < n; i++) {
        winner = max(winner, a[i]);
        wins[winner]++;
    }
    wins[n] = inf;
    for (int i = 0; i < q; i++) {
        int ind, k;
        scanf("%lld%lld", &ind, &k);
        int val = a[ind - 1];
        int round = 0;
        if (ind > 2) {
            round = ind - 2;
        }
        k -= round;
        int ans = 0;
        if (k > 0) {
            ans = min(k, wins[val]);
        }
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
