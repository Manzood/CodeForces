#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 1;
    set<int> cur;
    for (int i = 0; i < n; i++) {
        if (x % a[i] == 0) {
            vector<int> temp;
            for (auto val : cur) {
                if (x % (a[i] * val) == 0) {
                    if (a[i] * val == x) {
                        ans++;
                        cur.clear();
                        temp.clear();
                        break;
                    } else {
                        temp.push_back(a[i] * val);
                    }
                }
            }
            for (auto t : temp) {
                cur.insert(t);
            }
            cur.insert(a[i]);
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
