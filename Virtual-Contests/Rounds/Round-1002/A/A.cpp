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
    set<int> aset, bset;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        aset.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        bset.insert(b[i]);
    }
    bool ans = false;
    if ((int)aset.size() > 2)
        ans = true;
    else if ((int)aset.size() == 2 && (int)bset.size() > 1)
        ans = true;
    else if (bset.size() > 2)
        ans = true;
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
