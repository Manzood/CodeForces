#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k, x;
    scanf("%lld%lld%lld", &n, &k, &x);
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total ^= i;
    }
    bool possible = true;
    if (k % 2 == 0 && total != 0) possible = false;
    if (k & 1 && total != x) possible = false;
    // make pairs
    vector<int> marked(n + 1, false);
    vector<int> unmarked;
    vector<vector<int>> pairs;
    for (int i = 1; i <= n; i++) {
        if (!marked[i]) {
            if ((i ^ x) <= n && !marked[i ^ x]) {
                marked[i] = true;
                marked[i ^ x] = true;
                if ((i ^ x) != 0)
                    pairs.push_back({i, i ^ x});
                else
                    pairs.push_back({i});
            }
        }
        if (!marked[i]) unmarked.push_back(i);
    }
    int diff = (int)pairs.size() - k;
    if ((diff & 1) || diff < 0) possible = false;
    if (!possible) {
        printf("NO\n");
        return;
    }
    vector<vector<int>> ans;
    int used = 0;
    for (int i = 0; i < (int)pairs.size() - diff - 1; i++) {
        vector<int> cur;
        for (auto tmp : pairs[i]) {
            cur.push_back(tmp);
        }
        ans.push_back(cur);
        used++;
    }
    vector<int> cur;
    for (int i = used; i < (int)pairs.size(); i++) {
        for (auto tmp : pairs[i]) {
            cur.push_back(tmp);
        }
    }
    for (auto tmp : unmarked) cur.push_back(tmp);
    ans.push_back(cur);
    printf("YES\n");
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld ", (int)ans[i].size());
        for (int j = 0; j < (int)ans[i].size(); j++) {
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
