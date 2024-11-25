#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    int ans = 1;
    for (int k = 2; k <= n; k++) {
        bool flipped = false;
        string cur = s;
        for (int i = n - 1; i >= k - 1; i--) {
            int v = cur[i] - '0';
            if ((v ^ flipped) == 0) {
                flipped ^= 1;
                cur[i] = ((cur[i] - '0') ^ 1) + '0';
            }
        }
        if (test == 3 && k == 4) debug(cur);
        for (int i = k - 2; i >= 0; i--) {
            if (flipped) cur[i] = ((cur[i] - '0') ^ 1) + '0';
        }
        bool found = true;
        for (int i = 0; i < n; i++)
            if (cur[i] == '0') found = false;
        if (!found) {
            int ind = 0;
            while (cur[ind] == '0' && ind < n - 1) ind++;
            if (test == 3 && k == 4) debug(cur, ind);
            if ((n - ind) % k != 0) continue;
            for (int i = ind; i < n; i++)
                if (cur[i] != 1) break;
            found = true;
        }
        if (found) ans = k;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
