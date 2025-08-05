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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int h = a[k - 1];
    sort(a.begin(), a.end());
    int level = 1;
    for (int i = 0; i < n; i++) {
        if (h >= a[i]) continue;
        int time = a[i] - h;
        if (level + time - 1 > h) {
            break;
        }
        h = a[i];
        level += time;
    }

    printf(h == a[n - 1] ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
