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
    vector<vector<int>> a(n, vector<int>(n));
    vector<bool> found(2 * n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<int> out(2 * n);
    for (int i = 0; i < n; i++) {
        out[i + 1] = a[0][i];
        found[a[0][i] - 1] = true;
    }
    for (int i = 1; i < n; i++) {
        out[n + i] = a[n - 1][i];
        found[a[n - 1][i] - 1] = true;
    }
    int other = 1;
    for (int i = 0; i < 2 * n; i++) {
        if (!found[i]) other = i + 1;
    }
    out[0] = other;
    for (int i = 0; i < 2 * n; i++) {
        printf("%lld ", out[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
