#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query (int i, int j, int k) {
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int response; cin >> response;
    if (response == -1) exit(1);
    return response;
}

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 1, c = 2;
    int p = -1;
    debug (n);
    int prev = query (a, b, c);
    for (int i = 3; i < n; i++) {
        int cur = query(a, b, i);
        if (cur > prev) {
            c = i;
        }
    }
    cout << "found mx" << endl;
    int t1 = 0, t2 = 0;
    while (t1 == a || t1 == b || t1 == c) t1++;
    while (t2 == a || t2 == b || t2 == c || t2 == t1) t2++;
    int baseline = query (c, t1, t2);
    int aval = query (a, t1, t2);
    if (aval > baseline) {
        c = a;
        baseline = aval;
    }
    int bval = query (b, t1, t2);
    if (bval > baseline) c = b;
    int mx = c; // doesn't matter if it's max or min
    a = 0; b = 1;
    int cnt = 1;
    vector <bool> marked (n, false);
    marked[mx] = true;
    p = -1;
    int best_a = -1, best_b = -1;
    while (cnt < n) {
        while (marked[a]) a++;
        while (b == a || marked[b]) b++;
        int response = query (a, b, mx);
        marked[a] = true;
        marked[b] = true;
        if (response > p) {
            p = response;
            best_a = a;
            best_b = b;
        }
    }
    // compare a and b, mx
    c = 0;
    while (c == best_a || c == best_b || c == mx) c++;
    int mi = best_a;
    int val = query (best_a, c, mx);
    int val2 = query (best_b, c, mx);
    if (val > val2) mi = best_a;
    else (mi = best_b);
    cout << "! " << mi << " " << mx << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
