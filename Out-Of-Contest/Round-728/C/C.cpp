#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        int ans = 0;
        int p = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (i > 1) {
                cnt++;
                if (a[i] > a[i-1]) {
                    if (i > 2) p += cnt * (a[i] - a[i-1]);
                    p += a[i] + a[i-2];
                    ans -= p;
                    // ans -= a[i];
                }
            }
        }

        printf("%lld\n", ans);
    }
}
