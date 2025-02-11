#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int response;
    cin >> response;
    return response;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    if ((int)s.size() == n) {
        // query 1 and n
        int f = 0, sec = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) f = i;
            if (a[i] == n) sec = i;
        }
        int r1 = query(f + 1, sec + 1);
        int r2 = query(sec + 1, f + 1);
        bool b = false;
        if (r1 == r2) {
            b = true;
            if (r1 < n - 1) b = false;
        }
        if (b) {
            cout << "! B" << endl;
        } else {
            cout << "! A" << endl;
        }
    } else {
        int missing = -1;
        for (int i = 1; i <= n; i++)
            if (!s.count(i)) missing = i;
        int other = 1;
        if (other == missing) other++;
        int response = query(missing, other);
        if (response != 0) {
            cout << "! B" << endl;
        } else {
            cout << "! A" << endl;
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
