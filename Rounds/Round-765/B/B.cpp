#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve(int test_no) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    map <int, int> prev_index;
    set <int> s;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (s.count(a[i])) {
            int l = prev_index[a[i]] + 1;
            int r = n - i - 1;
            int len = l + r;
            ans = max (ans, len);
        } else {
            s.insert(a[i]);
        }
        prev_index[a[i]] = i;
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
