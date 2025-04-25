#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n), b(n);
    int ind = -1, val = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    bool possible = true;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (b[i] != -1) {
            if (ind == -1) {
                ind = i;
                val = a[i] + b[i];
            } else {
                if (a[i] + b[i] != val) {
                    possible = false;
                }
            }
        }
    }
    int ans = 1;
    if (ind == -1) {
        sort(a.begin(), a.end());
        ans = max(a.front() + k + 1 - a.back(), 0LL);
    } else {
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                if (a[i] > val || a[i] + k < val) possible = false;
            }
        }
    }
    if (!possible) ans = 0;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
