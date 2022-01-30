#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int a, b;
    scanf("%lld%lld", &a, &b);
    int ans = b - a;
    int cnt = 30;
    int tempcnt = cnt;
    int cur = 0;
    while (a < b) {
        cnt = tempcnt;
        int temp = b;
        int temp2 = a;
        while (temp > temp2) {
            int val = 1LL << cnt;
            temp %= val;
            temp2 %= val;
            cnt--;
        }
        // b += (temp2 - temp);
        // a |= b;
        // assert (a == b);
        ans = min (ans, cur + temp2 - temp + 1);
        a++;
        cur++;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
