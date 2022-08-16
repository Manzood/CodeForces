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
    k %= 4;
    if (k == 0) {
        printf("NO\n");
    } else if (k == 1 || k == 3) {
        printf("YES\n");
        for (int i = 0; i < n; i += 2) {
            printf("%lld %lld\n", i + 1, i + 2);
        }
    } else {
        printf("YES\n");
        for (int i = 0; i < n; i += 2) {
            if (i % 4 == 0)
                printf("%lld %lld\n", i + 2, i + 1);
            else
                printf("%lld %lld\n", i + 1, i + 2);
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
