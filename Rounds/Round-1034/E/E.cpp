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
    vector<int> a(n), cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
    }

    int mex = 0;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0) {
            mex = i;
            break;
        }
    }
    vector<int> extras(n + 1, 0), rsum(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        extras[i] = extras[i - 1] + max(cnt[i - 1] - 1, 0LL);
    }
    for (int i = n; i >= 0; i--) {
        rsum[i] = cnt[i] + rsum[i + 1];
    }

    vector<int> sum(n + 2, 0);
    for (int i = mex; i >= 0; i--) {
        sum[cnt[i]]++;
        sum[extras[i] + rsum[i] + 1]--;
    }

    int val = 0;
    for (int i = 0; i <= n; i++) {
        val += sum[i];
        printf("%lld ", val);
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
