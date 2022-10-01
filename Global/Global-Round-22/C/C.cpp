#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// state = 0 -> alice has even sum
int getans(int turn, int odd, int even, int state,
           vector<vector<vector<int>>>& dp) {
    int retval = 1;
    if (odd == 0 && even == 0) return state;
    if (dp[odd][even][state] != -1) return dp[odd][even][state];
    if (turn == 0) {
        if (odd > 0) retval &= getans(1, odd - 1, even, !state, dp);
        if (even > 0) retval &= getans(1, odd, even - 1, state, dp);
    } else {
        retval = 0;
        if (odd > 0) retval |= getans(0, odd - 1, even, state, dp);
        if (even > 0) retval |= getans(0, odd, even - 1, state, dp);
    }
    dp[odd][even][state] = retval;
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1)
            odd++;
        else
            even++;
    }
    vector<vector<vector<int>>> dp(
        odd + 1, vector<vector<int>>(even + 1, vector<int>(2, -1)));
    int ans = getans(0, odd, even, 0, dp);
    ans ? printf("Bob\n") : printf("Alice\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
