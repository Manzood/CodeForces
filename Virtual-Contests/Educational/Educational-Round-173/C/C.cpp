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
    int x = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] != 1 && a[i] != -1) x = i;
    }
    int mx = 0, mi = 0;
    int cur1 = 0, cur2 = 0;
    for (int i = 0; i < x; i++) {
        cur1 += a[i], cur2 += a[i];
        mx = max(mx, cur1);
        if (cur1 < 0) cur1 = 0;
        mi = min(mi, cur2);
        if (cur2 > 0) cur2 = 0;
    }
    cur1 = 0, cur2 = 0;
    for (int i = x + 1; i < n; i++) {
        cur1 += a[i], cur2 += a[i];
        mx = max(mx, cur1);
        if (cur1 < 0) cur1 = 0;
        mi = min(mi, cur2);
        if (cur2 > 0) cur2 = 0;
    }
    // now solve for subarrays including x
    cur1 = 0;
    int lowest1 = 0, highest1 = 0;
    for (int i = x - 1; i >= 0; i--) {
        cur1 += a[i];
        lowest1 = min(lowest1, cur1);
        highest1 = max(highest1, cur1);
    }
    cur2 = 0;
    int lowest2 = 0, highest2 = 0;
    for (int i = x + 1; i < n; i++) {
        cur2 += a[i];
        lowest2 = min(lowest2, cur2);
        highest2 = max(highest2, cur2);
    }
    int mx2 = a[x] + highest1 + highest2;
    int mi2 = a[x] + lowest1 + lowest2;
    vector<int> tmp;
    for (int i = mi; i <= mx; i++) {
        tmp.push_back(i);
    }
    for (int i = mi2; i <= mx2; i++) {
        tmp.push_back(i);
    }
    set<int> s;
    for (auto val : tmp) s.insert(val);
    vector<int> ans;
    for (auto val : s) ans.push_back(val);
    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
