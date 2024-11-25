#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n + m + 1), b(n + m + 1);
    for (int i = 0; i < n + m + 1; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n + m + 1; i++) {
        scanf("%lld", &b[i]);
    }
    vector<int> p, t;
    int val = 0;
    vector<int> chosen(n + m + 1);  // TODO consider this one as well
    for (int i = 0; i < n + m + 1; i++) {
        if (a[i] > b[i]) {
            if ((int)p.size() >= n) {
                chosen[i] = b[i];
            } else {
                chosen[i] = a[i];
            }
            p.push_back(i);
        } else {
            if ((int)t.size() >= m) {
                chosen[i] = a[i];
            } else {
                chosen[i] = b[i];
            }
            t.push_back(i);
        }
        val += chosen[i];
    }
    vector<int> ans(n + m + 1, val);
    for (int i = 0; i < n + m + 1; i++) {
        if (a[i] > b[i]) {
            if ((int)p.size() > n && i < p[n]) {
                ans[i] -= a[i];
                ans[i] += a[p[n]];
                ans[i] -= b[p[n]];
            } else {
                ans[i] -= chosen[i];
            }
        } else {
            if ((int)t.size() > m && i < t[m]) {
                ans[i] -= b[i];
                ans[i] -= a[t[m]];
                ans[i] += b[t[m]];
            } else {
                ans[i] -= chosen[i];
            }
        }
    }
    for (int i = 0; i < n + m + 1; i++) {
        printf("%lld%c", ans[i], " \n"[i == n + m]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
