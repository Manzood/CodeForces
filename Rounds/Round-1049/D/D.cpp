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
    vector<vector<int>> a(n, vector<int>(3));
    int val = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i][1], &a[i][2]);
        a[i][0] = a[i][1] + a[i][2];
        val += a[i][2];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n / 2; i++) {
        val -= a[i][0];
    }

    int best = 0;
    if (n & 1) {
        for (int i = 0; i < n; i++) {
            int cur = val;
            if (i < n / 2) {
                cur += a[i][1];
                cur -= a[n / 2][0];
            } else {
                cur -= a[i][2];
            }
            best = max(best, cur);
        }
    } else {
        best = val;
    }

    for (int i = 0; i < n; i++) {
        best += a[i][2] - a[i][1];
    }

    printf("%lld\n", best);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
