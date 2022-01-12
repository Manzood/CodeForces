#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve(int test_no) {
    int n, l;
    scanf("%lld%lld", &n, &l);
    vector <int> a(n);
    vector <int> cnt(l, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < l; j++) {
            if ((1LL << j) & a[i]) {
                cnt[j]++;
            }
        }
    }
    int y = 0;
    for (int i = 0; i < l; i++) {
        if (cnt[i] > n / 2) {
            y += (1LL << i);
        }
    }
    printf("%lld\n", y);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
