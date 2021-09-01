#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, x, k;
        scanf("%lld%lld%lld", &n, &x, &k);
        int ans = 0;
        int val = k / x;
        ans = n * val;
        val = min (n, val);
        ans -= ((val) * (val + 1)) / 2;
        printf("%lld\n", ans);
    }
}
