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
    vector<int> a(n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i & 1) {
            ans -= a[i];
        } else {
            ans += a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);
            int cur = 0;
            for (int x = 0; x < n; x++) {
                if (x & 1) {
                    cur -= a[x];
                } else {
                    cur += a[x];
                }
            }

            ans = max(ans, cur + j - i);
            swap(a[i], a[j]);
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
