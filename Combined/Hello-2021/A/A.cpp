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
        int n, k;
        scanf("%lld%lld", &n, &k);
        if (k > (n / 2) + (n % 2)) {
            printf("-1\n");
        } else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i % 2 == 0 && i == j && cnt < k) {
                        printf("R");
                        cnt++;
                    } else {
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
    }
}
