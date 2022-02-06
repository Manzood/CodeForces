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
    int a = 0;
    int b = 1, c = 2;
    int best_b = 1, best_c = 2;
    int p = query (a, b, c);
    b += 2; c += 2;
    while (c <= n - 1) {
        int response = query (a, b, c);
        if (response > p) {
            best_b = b;
            best_c = c;
        }
        b += 2; c += 2;
    }
    int mx = best_b;
    if (n % 2 == 0) {
        // recheck this logic once
        int response = query (a, best_c, n - 1);
        if (response > p) mx = n - 1;
        else if (response == p) mx = best_c;
        else mx = best_b;
    } else {
        // compare b and c
        int temp = 0;
        while (temp == a || temp == best_b || temp == best_c) temp++;
        int v1 = query (a, best_b, temp);
        int v2 = query (a, best_c, temp);
        if (v2 > v1) mx = best_c;
    }
    // found mx
    // debug (mx);
    int ta = 0, tb = 1;
    while (ta == mx) ta++;
    while (tb == mx || tb == ta) tb++;
    vector <bool> marked (n, false);
    int val = query (ta, tb, mx);
    marked[ta] = true; marked[tb] = true; marked[mx] = true;
    int rem = n - 3;
    int best_a = ta;
    best_b = tb;
    while (rem >= 2) {
        while (marked[ta]) ta++;
        while (marked[tb] || tb == ta) tb++;
        int nval = query (ta, tb, mx);
        marked[ta] = true; marked[tb] = true; marked[mx] = true;
        if (nval > val) {
            best_a = ta;
            best_b = tb;
            val = nval;
        }
        rem -= 2;
    }
    int mi = best_a;
    if (rem) {
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (!marked[i]) ind = i;
        }
        // debug(ind);
        int response = query (mx, best_a, ind);
        if (response > val) {
            mi = ind;
        } else if (response < val) {
            mi = best_b;
        }
    } else {
        int temp = 0;
        while (temp == best_a || temp == best_b || temp == mx) temp++;
        int v1 = query (best_a, temp, mx);
        int v2 = query (best_b, temp, mx);
        if (v2 > v1) mi = best_b;
    }
    cout << "! " << mi + 1 << " " << mx + 1 << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
