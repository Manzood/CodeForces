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
    int cpy = n, dig = 0;
    string base;
    while (cpy) {
        dig++;
        base += (cpy % 10) + '0';
        cpy /= 10;
    }
    reverse(base.begin(), base.end());
    vector<pair<int, int>> ans;
    for (int b = 1; b <= 10000; b++) {
        for (int len = 1; len <= 10; len++) {
            if ((len + b) % dig != 0) continue;
            int a = (len + b) / dig;
            if (a > 10000) continue;
            string x;
            while ((int)x.size() < len) {
                x += base;
            }
            int val = 0;
            for (int i = 0; i < len; i++) {
                val *= 10;
                val += (x[i] - '0');
            }
            int other = n * a - b;
            if (val == other) {
                ans.push_back({a, b});
            }
        }
    }
    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld %lld\n", ans[i].first, ans[i].second);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
