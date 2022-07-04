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
    vector <int> final;
    bool ans = true;
    int zc = 0, pc = 0, nc = 0;
    set <int> nums;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 0) {
            zc++;
            if (zc < 2) final.push_back(0);
        } else if (a[i] > 0) {
            pc++;
            if (pc > 2) ans = false;
            final.push_back(a[i]);
        } else {
            nc++;
            if (nc > 2) ans = false;
            final.push_back(a[i]);
        }
        nums.insert(a[i]);
    }
    if (ans) {
        int len = final.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (j == i) continue;
                for (int k = 0; k < len; k++) {
                    if (k == i || k == j) continue;
                    if (!nums.count(final[i] + final[j] + final[k])) {
                        ans = false;
                    }
                }
            }
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
