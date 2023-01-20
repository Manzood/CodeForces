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
    vector<int> occurances(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        occurances[a[i] - 1]++;
    }
    bool possible = true;
    int rep = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (occurances[i] > 2)
            possible = false;
        else if (occurances[i] == 2)
            rep++;
        else if (occurances[i] == 0)
            cnt++;
    }
    vector<int> mp(n, -1);
    if (rep != cnt)
        possible = false;
    else {
        int f = n - 1, s = n - 1;
        while (rep) {
            rep--;
            while (occurances[f] != 2) f--;
            while (occurances[s] != 0) s--;
            if (s > f) possible = false;
            mp[f] = s;
            f--;
            s--;
        }
    }
    if (possible) {
        printf("YES\n");
        vector<int> p(n), q(n);
        vector<bool> found(n, false);
        for (int i = 0; i < n; i++) {
            if (occurances[a[i] - 1] == 1) {
                q[i] = a[i];
                p[i] = a[i];
            } else if (occurances[a[i] - 1] == 2) {
                q[i] = a[i];
                p[i] = mp[a[i] - 1] + 1;
                if (found[a[i] - 1]) swap(p[i], q[i]);
                found[a[i] - 1] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%lld ", p[i]);
        }
        printf("\n");
        for (int i = 0; i < n; i++) {
            printf("%lld ", q[i]);
        }
        printf("\n");
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
