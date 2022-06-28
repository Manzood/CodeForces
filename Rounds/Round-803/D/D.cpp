#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int retval = 0;
    for (int i = 0; i < r - l + 1; i++) {
        int temp;
        cin >> temp;
        if (temp == -1) exit(1);
        if (temp >= l + 1 && temp <= r + 1) {
            retval++;
        }
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    int l = 0;
    int r = n - 1;
    int ans = (l + r) / 2;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = query(l, mid);
        if (cnt % 2 == 1) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << "! " << ans + 1 << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
