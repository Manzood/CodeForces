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
    bool alice = true;
    bool guarantee = false;
    if (a[0] == 1) alice = false;
    for (int i = 1; i < n; i++) {
        if (a[i] == 1) {
            guarantee = true;
        }
    }
    if (!guarantee) {
        int ind = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[ind]) ind = i;
        }
        if (ind == 0) alice = false;
    }
    alice ? printf("Alice\n") : printf("Bob\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
