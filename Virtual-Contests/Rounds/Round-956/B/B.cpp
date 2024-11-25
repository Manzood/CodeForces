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
    vector<string> a(n), b(n);
    vector<int> row_a(n, 0), row_b(n, 0), col_a(m, 0), col_b(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            row_a[i] += a[i][j] - '0';
            col_a[j] += a[i][j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        for (int j = 0; j < m; j++) {
            row_b[i] += b[i][j] - '0';
            col_b[j] += b[i][j] - '0';
        }
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (row_a[i] % 3 != row_b[i] % 3) {
            ans = false;
        }
    }
    for (int i = 0; i < m; i++) {
        if (col_a[i] % 3 != col_b[i] % 3) {
            ans = false;
        }
    }
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
