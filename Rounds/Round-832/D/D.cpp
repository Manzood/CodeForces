#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    vector<int> pref(n + 1, 0);
    map<int, int> mp;
    map<int, int> mp2;
    vector<int> p(n, -1);
    vector<int> zero(n + 1, n + 2);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pref[i + 1] ^= a[i];
        pref[i + 1] ^= pref[i];
        if (mp.count(pref[i + 1])) {
            int val = mp[pref[i + 1]];
            if ((i - val) % 2 == 1) p[i] = val;
        }
        if (mp2.count(pref[i + 1])) {
            int val = mp2[pref[i + 1]];
            if ((i - val) % 2 == 1) p[i] = val;
        }
        if (i > 0) {
            if (i % 2 == 0) mp[pref[i]] = i - 1;
            if (i % 2 == 1) mp2[pref[i]] = i - 1;
        }
        if (a[i] == 0) {
            zero[i + 1] = i;
            zero[i + 1] = min(zero[i + 1], zero[i]);
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        l--;
        r--;
        int val = pref[r + 1] ^ pref[l];
        if (zero[r + 1] <= l) {
            printf("0\n");
            continue;
        }
        if (val != 0 || ((r - l + 1) <= 2)) {
            printf("-1\n");
            continue;
        }
        if ((r - l + 1) % 2 == 1) {
            printf("1\n");
            continue;
        }
        if (a[l] == 0 || a[r] == 0) {
            printf("1\n");
            continue;
        }
        if (p[r] >= l + 2) {
            if (zero[p[r] + 1] <= l) {
                printf("1\n");
            } else {
                printf("2\n");
            }
            continue;
        } else {
            if (p[r] == l) {
                if (a[l] == 0) {
                    printf("1\n");
                    continue;
                }
            }
        }
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
