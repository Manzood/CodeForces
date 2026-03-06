#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int u, int v) {
    cout << u + 1 << " " << v + 1 << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

bool check(int step, int n) {
    for (int i = 0; i + step < n; i++) {
        if (query(i, i + step)) return true;
    }
    return false;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;

    for (int step = 1; step < n; step++) {
        if (check(step, n)) return;
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
