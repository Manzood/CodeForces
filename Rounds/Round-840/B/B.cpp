#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int inf = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].first);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].second);
    }
    sort(a.begin(), a.end());
    vector<int> mi(n, inf);
    mi[n - 1] = a[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        mi[i] = min(mi[i + 1], a[i].second);
    }
    int dmg = 0;
    int ptr = 0;
    while (ptr < n && k > 0) {
        dmg += k;
        while (a[ptr].first <= dmg && ptr < n) ptr++;
        if (ptr == n) break;
        k -= mi[ptr];
    }
    string ans = "NO";
    if (ptr == n) {
        ans = "YES";
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
