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
        int n, m;
        scanf("%lld%lld", &n, &m);
        if (n == m && n == 1) {
            printf("0\n");
            continue;
        }
        if (min (n, m) == 1) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
}
