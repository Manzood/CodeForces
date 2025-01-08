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
    vector<int> a(n), b(n);
    map<int, int> mp;
    int mx = 0, mode;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mp[a[i]]++;
        if (mp[a[i]] > mx) {
            mode = a[i];
            mx = mp[a[i]];
        }
        b[i] = mode;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", b[i]);
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
