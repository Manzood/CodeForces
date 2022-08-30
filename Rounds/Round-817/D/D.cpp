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
    int score = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            score += i;
        } else {
            score += n - i - 1;
        }
    }
    vector<int> improvements;
    for (int i = 0; i < n; i++) {
        int imp;
        if (s[i] == 'L') {
            imp = (n - i - 1) - i;
        } else {
            imp = i - (n - i - 1);
        }
        improvements.push_back(imp);
    }
    sort(improvements.begin(), improvements.end());
    int cur = score;
    int mx = score;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        cur += improvements[i];
        mx = max(cur, mx);
        ans.push_back(mx);
    }
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
