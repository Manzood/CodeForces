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
    set<int> nums;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (nums.count(a[i])) ans = false;
        nums.insert(a[i]);
    }
    sort(a.begin(), a.end());
    for (int x = 2; x <= 100; x++) {
        vector<int> slots(x, 0);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (j == i) continue;
        //         int rem = abs(a[j] - a[i]);
        //         slots[rem % x]++;
        //     }
        // }
        slots[a[0] % x]++;
        for (int i = 1; i < n; i++) {
            slots[(a[i]) % x]++;
        }
        bool f = true;
        for (int i = 0; i < x; i++) {
            if (slots[i] < 2) f = false;
        }
        if (f) ans = false;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
