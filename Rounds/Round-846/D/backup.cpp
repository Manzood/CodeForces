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
    int moves = cnt;
    int ans = 0;
    int response = query(1);
    int diff = response - (cnt - 1);
    ans += (1LL << diff);
    int init = 0;
    while (--moves) {
        cnt = response;
        int val = 0;
        int turning = 0;
        for (int i = init; i <= init + diff; i++) {
            val += (1LL << i);
            turning++;
        }
        init += diff;
        response = query(val);
        diff = response - (cnt - turning);
        ans += (1LL << (init + diff));
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
