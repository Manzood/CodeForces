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
    if (n == 3) {
        printf("NO\n");
        return;
    }
    if (n & 1) {
        int val = n / 2;
        int f = val - 1;
        int s = val;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans.push_back(f);
            } else {
                ans.push_back(-s);
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans.push_back(1);
            } else {
                ans.push_back(-1);
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
