#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, H, M;
    scanf("%lld%lld%lld", &n, &H, &M);
    vector<pair<int, int>> alarms(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &alarms[i].first, &alarms[i].second);
    }
    int ansh = (int)1e9 + 7, ansm = (int)1e9 + 7;
    for (int i = 0; i < n; i++) {
        int h = alarms[i].first;
        int m = alarms[i].second;
        int curh = 0, curm = 0;
        curh = h - H;
        curm = m - M;
        if (curm < 0) {
            curh--;
            curm += 60;
        }
        if (curh < 0) curh += 24;
        if (curh < ansh) {
            ansh = curh;
            ansm = curm;
        } else if (curh == ansh && curm < ansm) {
            ansh = curh;
            ansm = curm;
        }
    }
    printf("%lld %lld\n", ansh, ansm);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
