#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    int ans = -1;

    for (int i = l; i <= r; i++) {
        vector<int> digits;
        int cur = i;
        while (cur) {
            digits.push_back(cur % 10);
            cur /= 10;
        }
        set<int> other(digits.begin(), digits.end());

        if (other.size() == digits.size()) {
            ans = i;
            break;
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
