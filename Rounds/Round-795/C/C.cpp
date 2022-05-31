#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    // calculate value
    int tot = 0;
    int ones = 0;
    for (int i = 0; i < n - 1; i++) {
        int val = s[i + 1] - '0';
        val += (s[i] - '0') * 10;
        tot += val;
        if (s[i] == '1') ones++;
    }
    if (s[n-1] == '1') ones++;
    int rdist = n + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            rdist = n - 1 - i;
            break;
        }
    }
    int ldist = n + 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ldist = i;
            break;
        }
    }
    if (rdist > 0 && rdist <= n && rdist <= k) {
        tot -= 10;
        s[n - 1] = '1';
        k -= rdist;
        if (rdist == n - 1) tot++;
    }
    if (ldist > 0 && ldist <= n && ldist <= k && ones) {
        if (ones != 1 || s[n-1] != '1') {
            tot--;
            k -= ldist;
        }
    }
    printf("%lld\n", tot);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
