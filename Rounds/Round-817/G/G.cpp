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
    vector<int> ans;
    if (n % 4 == 1) {
        ans = {2, 0, 4, 5, 3};
        n -= 5;
    } else if (n % 4 == 3) {
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(3);
        n -= 3;
    } else if (n % 4 == 2) {
        ans = {4, 1, 2, 12, 3, 8};
        n -= 6;
    }
    // make it a multiple of 4
    int val = (1LL) << 30;
    vector<int> odd, even;
    for (int i = 0; i < n / 2; i++) {
        // odd gets value
        odd.push_back(i + 13);
        even.push_back(i + 13 + val);
    }
    for (int i = 0; i < n / 2; i++) {
        ans.push_back(even[i]);
        ans.push_back(odd[i]);
    }
    // debug(ans);
    int o = 0, e = 0;
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld ", ans[i]);
        if (i & 1)
            o ^= ans[i];
        else
            e ^= ans[i];
    }
    assert(o == e);
    printf("\n");
    // if (o != e) printf("Test failed: %lld\n", test);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
