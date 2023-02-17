#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> ops(n, 0);
    set<int> active;
    for (int i = 0; i < n; i++) active.insert(i);
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%lld", &type);
        if (type == 1) {
            int l, r;
            scanf("%lld%lld", &l, &r);
            l--;
            r--;
            auto it = active.lower_bound(l);
            while (it != active.end() && *it <= r) {
                int cur = 0;
                while (a[*it]) {
                    cur += a[*it] % 10;
                    a[*it] /= 10;
                }
                a[*it] = cur;
                if (++ops[*it] >= 3) {
                    it = active.erase(it);  // c++-11
                } else {
                    ++it;
                }
            }
        } else {
            int ind;
            scanf("%lld", &ind);
            --ind;
            printf("%lld\n", a[ind]);
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
