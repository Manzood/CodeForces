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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int firstindex = -1, lastindex = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i+1]) {
            if (firstindex == -1) {
                firstindex = i;
            } else {
                lastindex = i;
            }
        }
    }
    int ans = 0;
    if (lastindex > 0) {
        ans = lastindex - 1 - firstindex;
        if (ans <= 0) {
            ans = 1;
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
