#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mp[a[i]]++;
    }
    vector<int> occ;
    for (auto pp : mp) {
        occ.push_back(pp.second);
    }
    sort(occ.begin(), occ.end());
    int cur = 0, val = 0;
    for (int i = 0; i < (int)occ.size(); i++) {
        val += occ[i];
        if (val > k) {
            break;
        }
        cur = i + 1;
    }
    printf("%lld\n", max((int)occ.size() - cur, 1LL));
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
