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
        int x, y;
        scanf("%lld%lld", &x, &y);
        if ((x + y) % 2 == 1) {
            printf("-1 -1\n");
            continue;
        } else {
            int val = (x + y) / 2;
            if (val == 0) {
                printf("0 0\n");
            } else {
                if (x % 2 == 0) {
                    printf("%lld %lld\n", x / 2, y / 2);
                } else {
                    printf("%lld %lld\n", x / 2 + 1, y / 2);
                }
            }
        }
    }
}
