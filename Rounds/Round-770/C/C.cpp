#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    int jump = n + (n & 1);
    vector <vector <int>> ans(n, vector <int>(k));
    bool possible = true;
    for (int i = 0; i < n; i++) {
        int cur = i + 1;
        for (int j = 0; j < k; j++) {
            ans[i][j] = cur;
            if (cur > n * k) possible = false;
            cur += jump;
        }
    }
    if (possible) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                printf("%lld ", ans[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
