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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subset ends here
            int zeroes = 0, nonzeroes = 0;
            for (int x = i; x <= j; x++) {
                if (a[x] == 0) zeroes++;
                else nonzeroes++;
            }
            // int val = 2 * zeroes + nonzeroes;
            // if (test == 2) debug (i, j, val, zeroes, nonzeroes);
            ans += 2 * zeroes + nonzeroes;
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
