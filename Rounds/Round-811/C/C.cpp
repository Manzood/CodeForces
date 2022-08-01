#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int s;
    scanf("%lld", &s);
    vector<int> ans;
    int val = 9;
    while (s) {
        if (s > val) {
            s -= val;
            ans.push_back(val);
            val--;
        } else {
            ans.push_back(s);
            s = 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld", ans[i]);
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
