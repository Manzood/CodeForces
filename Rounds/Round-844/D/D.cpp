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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = a[j] - a[i];
            for (int k = 1; k * k < diff; k++) {
                if (diff % k == 0) {
                    int cnt = 0;
                    int f1 = diff / k;
                    int f2 = k;
                    if (f1 < f2) swap(f1, f2);
                    int v1 = (f1 + f2) / 2;
                    int v2 = (f1 - f2) / 2;
                    if ((f1 + f2) % 2 == 1 || (f1 - f2) % 2 == 1) continue;
                    if (v1 * v1 - v2 * v2 != diff) continue;
                    if (a[j] > v1 * v1 || a[i] > v2 * v2) continue;
                    // found a and b?
                    int add = v1 * v1 - a[j];
                    // debug(i, j, diff, k, add);
                    for (auto x : a) {
                        int cur = x + add;
                        int s = (int)sqrt(cur);
                        if (s * s == cur) cnt++;
                    }
                    ans = max(ans, cnt);
                }
            }
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
