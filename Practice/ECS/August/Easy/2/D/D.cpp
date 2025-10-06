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
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        freq[a[i]]++;
    }

    int target = 0, cnt = 0;
    for (auto x : freq) {
        if (x.second > cnt) {
            cnt = x.second;
            target = x.first;
        }
    }

    int x = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            x = i;
            break;
        }
    }

    vector<vector<int>> ans;
    for (int i = x - 1; i >= 0; i--) {
        if (a[i] == target) continue;
        if (a[i] < target)
            ans.push_back({1, i + 1, i + 2});
        else
            ans.push_back({2, i + 1, i + 2});
    }
    for (int i = x + 1; i < n; i++) {
        if (a[i] == target) continue;
        if (a[i] < target)
            ans.push_back({1, i + 1, i});
        else
            ans.push_back({2, i + 1, i});
    }

    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld %lld %lld\n", ans[i][0], ans[i][1], ans[i][2]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
