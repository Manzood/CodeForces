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
        vector <int> a(n), b(n);
        vector <int> firstindex(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
            firstindex[b[i] / 2 - 1] = i;
        }
        for (int i = n - 2; i >= 0; i--) {
            firstindex[i] = min (firstindex[i], firstindex[i + 1]);
        }
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            cur += i;
            int ind = (a[i] - 1) / 2;
            cur += firstindex[ind];
            ans = min (ans, cur);
        }
        printf("%lld\n", ans);
    }
}
