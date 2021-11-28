#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        scanf("%lld%lld%lld", &n, &a, &b);
        if ((a > n / 2 + 1) || (b < (n / 2))) {
            printf("-1\n");
            continue;
        }
        if (b == n / 2) {
            if (a != b + 1) {
                printf("-1\n");
                continue;
            }
        }
        if (a == n / 2 + 1) {
            if (b != a - 1) {
                printf("-1\n");
                continue;
            }
        }

        vector <int> ans(n);

        ans[0] = a;
        int val = n;
        for (int i = 1; i < n / 2; i++) {
            while (val == b || val == a) val--;
            ans[i] = val--;
        }
        for (int i = n / 2; i < n - 1; i++) {
            while (val == a || val == b) val--;
            ans[i] = val--;
        }
        ans[n-1] = b;

        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}
