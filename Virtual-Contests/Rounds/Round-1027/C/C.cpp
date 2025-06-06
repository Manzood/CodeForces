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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    vector<int> out;
    out.push_back(a[0]);
    bool skipped = false;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) continue;
        if (skipped) {
            out.push_back(a[i]);
            skipped = false;
        } else {
            if (a[i] > a[i - 1] + 1) {
                out.push_back(a[i]);
            } else {
                skipped = true;
            }
        }
    }

    printf("%lld\n", (int)out.size());
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
