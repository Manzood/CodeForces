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
    int moves = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        if (i < n - 1) {
            if (a[i] == a[i + 1]) {
                a[i + 1] = 0;
                a[i] = 0;
            }
        }
        if (i < n - 2) {
            if ((a[i + 1] ^ a[i]) == a[i + 2]) {
                a[i + 1] = a[i + 2];
                // moves++;
            }
        }
        moves++;
        if (test == 6) {
            debug(i, moves);
        }
    }
    printf("%lld\n", moves);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
