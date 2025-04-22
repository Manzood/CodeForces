#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int getMedian(vector<int>& a) {
    sort(a.begin(), a.end());
    assert((int)a.size() > 0);
    return a[((int)a.size() - 1) / 2];
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    bool possible = false;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int l = 0; l < n - 2; l++) {
        for (int r = l + 2; r < n; r++) {
            vector<int> x, y, z;
            for (int cur = 0; cur <= l; cur++) {
                x.push_back(a[cur]);
            }
            for (int cur = l + 1; cur < r; cur++) {
                y.push_back(a[cur]);
            }
            for (int cur = r; cur < n; cur++) {
                z.push_back(a[cur]);
            }
            vector<int> tmp = {getMedian(x), getMedian(y), getMedian(z)};
            sort(tmp.begin(), tmp.end());
            if (tmp[1] <= k) {
                possible = true;
            }
        }
    }
    if (possible) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
