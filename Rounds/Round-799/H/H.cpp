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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 1, l = 0, r = 0, output = a[0];
    map<int, int> first;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        if (first.count(a[i])) {
            int len = i - first[a[i]] + 1;
            cnt[a[i]]++;
            int val = cnt[a[i]] - (len - cnt[a[i]]);
            if (val > ans) {
                ans = val;
                output = a[i];
                l = first[a[i]];
                r = i;
            }
            if (val <= 0) {
                first[a[i]] = i;
                cnt[a[i]] = 1;
            }
        } else {
            first[a[i]] = i;
            cnt[a[i]] = 1;
        }
    }
    printf("%lld %lld %lld\n", output, l + 1, r + 1);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
