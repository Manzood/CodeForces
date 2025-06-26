#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, s, x;
    scanf("%lld%lld%lld", &n, &s, &x);
    vector<int> a(n), pref(n + 1, 0);
    map<int, vector<int>> mp;
    mp[0].push_back(-1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pref[i + 1] = pref[i] + a[i];
        mp[pref[i + 1]].push_back(i);  // TODO maybe change this
    }

    int lst_gt = -1, lst = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x)
            lst = i;
        else if (a[i] > x)
            lst_gt = i;

        int target = pref[i + 1] - s;
        // find count of indexes between lst_gt and lst - 1
        if (mp.count(target)) {
            int f = lower_bound(mp[target].begin(), mp[target].end(), lst_gt) -
                    mp[target].begin();
            int sec =
                upper_bound(mp[target].begin(), mp[target].end(), lst - 1) -
                mp[target].begin();
            ans += max(0LL, sec - f);
        }
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
