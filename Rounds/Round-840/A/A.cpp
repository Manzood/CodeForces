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
    vector<bool> ones(30, false), zeroes(30, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if ((1LL << j) & a[i]) {
                ones[j] = true;
            } else {
                zeroes[j] = true;
            }
        }
    }
    int mx = 0, mi = 0;
    for (int i = 0; i < 30; i++) {
        if (ones[i]) {
            mx += (1LL << i);
        }
        if (!zeroes[i]) mi += (1LL << i);
    }
    printf("%lld\n", mx - mi);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
