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
    vector<pair<int, int>> a(n);
    vector<int> occ(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].first);
        a[i].second = i;
        occ[a[i].first]++;
    }

    bool possible = true;
    for (int i = 1; i < n + 1; i++) {
        if (occ[i] % i != 0) possible = false;
    }

    if (!possible) {
        printf("-1\n");
        return;
    }

    sort(a.begin(), a.end());

    vector<int> out(n);
    int cur = 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && (a[i].first > a[i - 1].first || cnt == a[i].first)) {
            cnt = 0;
            cur++;
        }
        out[a[i].second] = cur;
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", out[i]);
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
