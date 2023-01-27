#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int val) {
    cout << "- " << val << endl;
    int response;
    cin >> response;
    if (response == -1) exit(0);
    return response;
}

void solve([[maybe_unused]] int test) {
    int cnt;
    cin >> cnt;
    int ans = 0;
    int rem = 0;
    while (cnt--) {
        int bits = query(1LL << rem);
        int diff = bits - cnt;
        rem = diff;
        ans += (1LL << rem);
    }
    cout << "! " << ans << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
