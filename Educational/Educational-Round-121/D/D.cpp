#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> temp(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &temp[i]);
    }
    sort (temp.begin(), temp.end());
    vector <int> a;
    a.push_back (0);
    for (int i = 1; i < n; i++) {
        if (temp[i] != temp[i-1]) {
            a.push_back (i);
        }
    }
    a.push_back (n);

    int ans = (int) 1e9 + 7;

    for (int i = 0; i <= 18; i++) {
        int ival = 1 << i;
        int ind1 = lower_bound(a.begin(), a.end(), ival) - a.begin();
        if (ind1 == (int) a.size() || a[ind1] != ival) ind1--;
        int rem1 = ival - a[ind1];

        for (int j = 0; j <= 18; j++) {
            int jval = 1 << j;
            int ind2 = lower_bound(a.begin(), a.end(), jval + a[ind1]) - a.begin();
            if (ind2 == (int) a.size() || a[ind2] != jval + a[ind1]) ind2--;
            if ((ind2 > 0 || ind2 < (int) a.size() - 1) && ind2 == ind1) continue;
            int rem2 = jval + a[ind1] - a[ind2];
            int fin = n - a[ind2];
            int k = 0;

            while ((1LL << k) < fin) k++;
            int rem3 = (1LL << k) - fin;
            int cost = rem1 + rem2 + rem3;
            // if (i == 4 && j == 1) {
            //     debug (cost);
            // }

            ans = min (ans, cost);
        }
    }
    int val = 0;
    while ((1LL << val) < n) val++;
    ans = min (ans, (1LL << val) - n + 2);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
