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
    vector<pair<int, int>> cpy(n);
    for (int i = 0; i < n; i++) {
        cpy[i] = {a[i], i};
    }
    sort(cpy.begin(), cpy.end());
    int ans = 0;
    if (k == 1) {
        for (int i = 1; i < n - 1; i++) {
            ans = max({ans, a[i] + a[0], a[i] + a[n - 1]});
        }
        ans = max(ans, a[0] + a[n - 1]);
    } else {
        for (int i = 0; i < n; i++) {
            vector<bool> marked(n, false);
            marked[i] = true;
            if (i > 0) {
                int mx = 0, ind = 0;
                for (int j = 0; j < i; j++) {
                    if (a[j] > mx) {
                        mx = a[j];
                        ind = j;
                    }
                }
                marked[ind] = true;
            }
            if (i < n - 1) {
                int mx = 0, ind = 0;
                for (int j = i + 1; j < n; j++) {
                    if (a[j] > mx) {
                        mx = a[j];
                        ind = j;
                    }
                }
                marked[ind] = true;
            }
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (marked[j]) cnt++;
            int ind = n - 1;
            while (cnt < k + 1) {
                while (marked[cpy[ind].second]) ind--;
                marked[cpy[ind--].second] = true;
                cnt++;
            }
            int s = 0;
            for (int j = 0; j < n; j++)
                if (marked[j]) s += a[j];
            ans = max(ans, s);
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
