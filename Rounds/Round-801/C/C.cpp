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
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector <vector <int>> ones(n, vector <int> (m, 0));
    vector <vector <int>> minus(n, vector <int> (m, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i < n - 1) {
                ones[i][j] = max(ones[i][j], ones[i + 1][j]);
                minus[i][j] = max(minus[i][j], minus[i + 1][j]);
            }
            if (j < m - 1) {
                ones[i][j] = max(ones[i][j], ones[i][j + 1]);
                minus[i][j] = max(minus[i][j], minus[i][j + 1]);
            }
            ones[i][j] += a[i][j] == 1;
            minus[i][j] += a[i][j] == -1;
        }
    }
    // if (test == 5) debug(ones);
    bool ans = true;
    if ((n + m - 1) & 1) ans = false;
    int req = n + m - 1;
    req /= 2;
    if (ones[0][0] < req) ans = false;
    if (minus[0][0] < req) ans = false;
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
