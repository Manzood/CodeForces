#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int dlog(int n) {
    int res = 0;
    while (n) {
        res++;
        n /= 10;
    }
    return res;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    map<int, int> amap, bmap;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        amap[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        bmap[b[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 9 && bmap[a[i]] < amap[a[i]]) {
            amap[a[i]]--;
            int val = dlog(a[i]);
            amap[val]++;
            a[i] = val;
            ans++;
        }
        if (b[i] > 9 && amap[b[i]] < bmap[b[i]]) {
            bmap[b[i]]--;
            int val = dlog(b[i]);
            bmap[val]++;
            b[i] = val;
            ans++;
        }
    }
    for (auto& x : amap) {
        if (x.first == 1) continue;
        int val = x.second - bmap[x.first];
        if (val > 0) {
            x.second = bmap[x.first];
            ans += val;
        }
    }
    for (auto& x : bmap) {
        if (x.first == 1) continue;
        int val = x.second - amap[x.first];
        if (val > 0) {
            x.second = amap[x.first];
            ans += val;
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
