#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int mod = 998244353;

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        sort(a.begin(), a.end());

        int ans = 1;

        int cnt = 1;
        for (int i = n - 3; i >= 0; i--) {
            if (a[i] == a[n-2]) {
                cnt++;
            }
        }

        if (a[n-1] == a[n-2]) {
            for (int i = 0; i < n; i++) {
                ans *= i + 1;
                ans %= mod;
            }
        } else if (a[n-1] - a[n-2] == 1) {
            for (int i = 0; i < n; i++) {
                ans *= i + 1;
                ans %= mod;
            }

            int v1 = 1;
            for (int i = 1; i <= cnt; i++) {
                v1 *= i;
                v1 %= mod;
            }

            int v2 = 1;
            for (int i = (2 + cnt) * (n - cnt - 1); i > (cnt + 1) * (n - cnt - 1); i--) {
                v2 *= i;
                v2 %= mod;
            }

            ans -= (v1 * v2);
            while (ans < 0) ans += mod;
        } else {
            ans = 0;
        }

        printf("%lld\n", ans);
    }
}
