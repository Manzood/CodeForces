#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n), pos(n + 1, -1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    int sqrt;
    for (sqrt = 1; sqrt * sqrt < n; sqrt++)
        ;
    vector<vector<int>> get(sqrt + 1, vector<int>(n, n + 1));
    for (int i = 1; i <= sqrt; i++) {
        for (int j = n - 1; j >= 0; j--) {
            int val = a[j] + i;
            if (val <= n) {
                int ind = pos[val];
                if (ind > j) get[i][j] = min(get[i][j], ind);
            }
            val = a[j] - i;
            if (val > 0) {
                int ind = pos[val];
                if (ind > j) get[i][j] = min(get[i][j], ind);
            }
            if (j < n - 1) get[i][j] = min(get[i][j], get[i][j + 1]);
        }
    }
    for (int query = 0; query < q; query++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        int ans = n;
        for (int i = 1; i <= sqrt; i++) {
            if (get[i][l] <= r) {
                ans = min(ans, i);
            }
        }
        vector<int> tmp;
        if (r - l + 1 <= sqrt) {
            for (int i = l; i <= r; i++) tmp.push_back(a[i]);
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 1; i < (int)tmp.size(); i++) {
            ans = min(ans, tmp[i] - tmp[i - 1]);
        }
        printf("%d\n", ans);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
