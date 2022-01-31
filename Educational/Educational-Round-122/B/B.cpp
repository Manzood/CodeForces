#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ones = 0;
    int zeroes = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ones++;
        else zeroes++;
    }
    if (ones > zeroes) {
        printf("%lld\n", zeroes);
    } else if (zeroes > ones) {
        printf("%lld\n", ones);
    } else {
        if (s[n-1] == '1') {
            ones--;
        } else {
            zeroes--;
        }
        printf("%lld\n", min(zeroes, ones));
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
