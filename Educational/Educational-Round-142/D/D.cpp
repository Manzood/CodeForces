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
    vector<vector<int>> a(n, vector<int>(m)), pos(n, vector<int>(m));
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
            pos[i][a[i][j] - 1] = j + 1;
        }
        int num = 0;
        for (int j = 0; j < m; j++) {
            num *= 10;
            num += pos[i][j];
            s.insert(num);
        }
    }
    for (int i = 0; i < n; i++) {
        int num = 0;
        int ans = 0;
        for (int j = 0; j < m; j++) {
            num += a[i][j];
            if (s.count(num)) {
                ans++;
            } else {
                break;
            }
            num *= 10;
        }
        printf("%lld ", ans);
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
