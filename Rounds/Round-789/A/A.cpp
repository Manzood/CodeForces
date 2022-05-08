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
    vector <int> a(n);
    int numzeroes = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 0) numzeroes++;
    }
    int ans = 0;
    if (numzeroes) {
        ans = n - numzeroes;
    } else {
        sort (a.begin(), a.end());
        bool equal = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i+1]) equal = true;
        }
        if (equal) {
            ans = n;
        } else {
            ans = n + 1;
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
