#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = (int)1e6 + 5;

vector<int> streak(MX);

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> first_diff(n, n);
    int cur = MX - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == cur) {
            streak[cur]++;
            first_diff[i] = i + streak[cur] + 1;
        } else {
            streak[cur] = 0;
            first_diff[i] = i + 1;
        }
        cur = a[i];
    }
    streak[cur] = 0;
    int q;
    scanf("%lld", &q);
    for (int query = 0; query < q; query++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        l--, r--;
        if (first_diff[l] <= r) {
            printf("%lld %lld\n", l + 1, first_diff[l] + 1);
        } else {
            printf("-1 -1\n");
        }
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
