#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    vector <int> orig(20, 0);
    for (int i = l; i <= r; i++) {
        for (int j = 0; j < 20; j++) {
            if ((1LL << j) & i) {
                orig[j]++;
            }
        }
    }
    vector <int> cur(20, 0);
    vector <int> a(r - l + 1);
    for (int i = 0; i < r - l + 1; i++) {
        scanf("%lld", &a[i]);
        for (int j = 0; j < 20; j++) {
            if ((1LL << j) & a[i]) {
                cur[j]++;
            }
        }
    }
    int x = 0;
    for (int i = 0; i < 20; i++) {
        if (cur[i] != orig[i]) {
            x += (1LL << i);
        }
    }
    printf("%lld\n", x);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
