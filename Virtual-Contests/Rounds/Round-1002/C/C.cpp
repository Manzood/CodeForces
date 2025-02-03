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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<int> len(n);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == 1)
                cur++;
            else
                break;
        }
        len[i] = cur;
    }
    sort(len.begin(), len.end());
    int cur = 0;
    int target = 1;
    while (cur < n) {
        while (cur < n && len[cur] < target) cur++;
        if (cur == n) break;
        cur++;
        target++;
    }
    target = min(target, n);
    printf("%lld\n", target);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
