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
    vector<int> a(n);
    map<int, int> occ;
    bool ans = false;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        occ[a[i]]++;
        if (occ[a[i]] >= 4) ans = true;
    }
    map<int, int> days;
    for (int i = 0; i < n; i++) {
        days[a[i] + 1]++;
        days[a[i] + 2]++;
    }
    set<int> known;
    for (auto d : days) {
        int day = d.first;
        if (known.count(day)) {
            if (occ[day - 1] >= 2) {
                ans = true;
            } else if (occ[day - 1] == 1)
                known.insert(day + 1);
        } else {
            if (occ[day - 1] >= 2) known.insert(day + 1);
        }
    }
    printf(ans ? "Yes\n" : "No\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
