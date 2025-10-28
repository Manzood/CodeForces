#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    string s;
    cin >> s;
    bool has = false;
    for (auto c : s) {
        if (c == 'B') has = true;
    }

    for (int query = 0; query < q; query++) {
        int val;
        scanf("%lld", &val);
        int ans = 0;
        if (has) {
            int ptr = 0;
            while (val > 0) {
                if (s[ptr] == 'B') {
                    val /= 2;
                } else {
                    val--;
                }
                ans++;
                ptr++;
                if (ptr == n) ptr = 0;
            }
        } else {
            ans = val;
        }

        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
