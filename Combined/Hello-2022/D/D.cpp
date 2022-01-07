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
        int n;
        scanf("%lld", &n);
        vector <vector <int>> a(2 * n);
        int cost = 0;
        for (int i = 0; i < 2 * n; i++) {
            a[i].resize (2 * n);
            for (int j = 0; j < 2 * n; j++) {
                scanf("%lld", &a[i][j]);
            }
        }
        for (int i = n; i < 2 * n; i++) {
            for (int j = n; j < 2 * n; j++) {
                // debug (i, j);
                cost += a[i][j];
            }
        }
        vector <int> temp = { a[n][0], a[2*n-1][0], a[0][n], a[0][2*n-1], a[n-1][n], a[n][n-1], a[2*n-1][n-1], a[n-1][2*n-1] };
        int min_add = *min_element(temp.begin(), temp.end());
        printf("%lld\n", cost + min_add);
    }
}
