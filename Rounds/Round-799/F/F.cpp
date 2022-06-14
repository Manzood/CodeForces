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
    set <int> occured;
    set <int> second;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] %= 10;
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
        int val = 3 - a[i];
        if (second.count(val)) ans = true;
        val = 13 - a[i];
        if (second.count(val)) ans = true;
        val = 23 - a[i];
        if (second.count(val)) ans = true;
        for (auto x: occured) {
            second.insert(x + a[i]);
        }
        occured.insert(a[i]);
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
