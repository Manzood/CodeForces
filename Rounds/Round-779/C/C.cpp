#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 4;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    bool possible = true;
    int onescnt = a[0] == 1;
    bool next = a[0] == n;
    int inversions = n - a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1] + 1) possible = false;
        if (next && a[i] != 1) {
            possible = false;
        } else {
            next = false;
        }
        if (n - a[i] > inversions) {
            if (test == 5) debug (i, inversions);
            possible = false;
        }
        inversions = min(inversions, n - a[i]);
        if (a[i] == n) next = true;
        onescnt += a[i] == 1;
    }
    if (onescnt != 1) possible = false;
    // cout << test << endl;
    // if (possible) debug (a);
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
