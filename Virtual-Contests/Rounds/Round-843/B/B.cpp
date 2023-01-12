#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
vector<int> cnt((int)2e5 + 7, 0);
vector<int> updated((int)2e5 + 7, -1);

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%lld", &k);
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%lld", &a[i][j]);
            if (updated[a[i][j]] < test) {
                cnt[a[i][j]] = 0;
                updated[a[i][j]] = test;
            }
            cnt[a[i][j]]++;
        }
    }
    bool found = false;
    for (int i = 0; i < n; i++) {
        bool cur = true;
        for (int j = 0; j < (int)a[i].size(); j++) {
            if (cnt[a[i][j]] == 1) {
                cur = false;
            }
        }
        found |= cur;
    }
    found ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
