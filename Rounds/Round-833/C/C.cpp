#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnt += a[i] == 0;
    }
    int j = 0;
    int ans = 0;
    int tmp = 0;
    while (a[j] != 0) {
        tmp += a[j];
        if (tmp == 0) ans++;
        j++;
    }
    j = 0;
    for (int i = 0; i < cnt; i++) {
        while (a[j] != 0) j++;
        // go to the next zero
        map<int, int> mp;
        int sum = 0;
        mp[0]++;
        j++;
        int best = 1;
        while (j < n && a[j] != 0) {
            sum += a[j];
            mp[sum]++;
            best = max(best, mp[sum]);
            j++;
        }
        ans += best;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
