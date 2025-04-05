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
    vector<int> cnt(10, 0);
    vector<int> req = {3, 1, 2, 1, 0, 1, 0, 0, 0, 0};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        bool found = true;
        for (int j = 0; j < 10; j++) {
            if (cnt[j] < req[j]) found = false;
        }
        if (found) {
            ans = i + 1;
            break;
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
