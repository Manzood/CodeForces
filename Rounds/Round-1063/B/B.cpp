#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// string get(int n, vector<pair<int, int>>& ans, vector<int> a) {
//     string out(n, '0');
//     for (auto x : ans) {
//         if (x.first > x.second) {
//             swap(x.first, x.second);
//         }
//         for (int i = x.first + 1; i < x.second; i++) {
//             if (a[i] > min(a[x.first], a[x.second]) &&
//                 a[i] < max(a[x.first], a[x.second])) {
//                 out[i] = '1';
//             }
//         }
//     }
//     return out;
// }

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), pos(n + 1, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pos[a[i]] = i;
    }
    string s;
    cin >> s;
    if (s[0] == '1' || s[n - 1] == '1' || s[pos[1]] == '1' ||
        s[pos[n]] == '1') {
        printf("-1\n");
        return;
    }

    vector<pair<int, int>> ans;
    ans.push_back({0, pos[1]});
    ans.push_back({0, pos[n]});
    ans.push_back({n - 1, pos[1]});
    ans.push_back({n - 1, pos[n]});
    ans.push_back({pos[1], pos[n]});

    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        if (ans[i].first > ans[i].second) {
            swap(ans[i].first, ans[i].second);
        }
        printf("%lld %lld\n", ans[i].first + 1, ans[i].second + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
