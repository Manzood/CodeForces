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
    set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s.insert(a[i]);
    }
    if ((int)s.size() == 1) {
        printf("-1\n");
        return;
    }
    int ans = n;
    if (a[0] != a[n - 1]) ans = 0;
    int cont = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[0])
            cont++;
        else {
            ans = min(ans, cont);
            cont = 0;
        }
    }
    ans = min(ans, cont);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
