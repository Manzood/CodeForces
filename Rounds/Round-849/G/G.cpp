#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = 1e18;

void solve([[maybe_unused]] int test) {
    int n, c;
    scanf("%lld%lld", &n, &c);
    int original = c;
    vector<int> a(n);
    vector<int> cleft(n, 0), cright(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cleft[i] = a[i] + i + 1;
        cright[i] = a[i] + n - i;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        left, right;
    vector<int> marked(n, false);
    vector<pair<int, int>> choices;
    for (int i = 0; i < n; i++) {
        left.push({cleft[i], i});
        right.push({cright[i], i});
    }
    int ans = 0;
    bool leftused = false;
    int leftmost = n;
    while (true) {
        while ((int)left.size() && marked[left.top().second]) left.pop();
        while ((int)right.size() && marked[right.top().second]) right.pop();
        if (!left.size() && !right.size()) break;
        pair<int, int> mi = {INF, -1};
        if (left.size()) mi = min(mi, left.top());
        if (right.size()) mi = min(mi, right.top());
        if (mi.first > c) break;
        c -= mi.first;
        marked[mi.second] = true;
        leftmost = min(leftmost, mi.second);
        leftused |= mi.second < (n + 1) / 2;
        choices.push_back(mi);
        ans++;
    }
    if (!leftused) {
        c = original;
        int cnt = 0;
        int ind = 0, mi = INF;
        for (int i = 0; i < n; i++) {
            if (cleft[i] < mi) {
                mi = cleft[i];
                ind = i;
            }
            if (marked[i]) {
                break;
            }
        }
        if (mi <= c) {
            cnt++;
            c -= mi;
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                if (i == ind) continue;
                tmp.push_back(cright[i]);
            }
            sort(tmp.begin(), tmp.end());
            int ptr = 0;
            while (ptr < (int)tmp.size() && c >= tmp[ptr]) {
                c -= tmp[ptr++];
                cnt++;
            }
        }
        ans = cnt;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
