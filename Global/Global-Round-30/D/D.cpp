#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<string> check(int n, int k, string& s, string& t) {
    vector<int> move(n);
    iota(move.begin(), move.end(), 0);
    int x = 0;
    for (int i = 0; i < n; i++) {
        while (i - x > k) x++;
        while (x <= i && s[x] != t[i]) x++;
        if (x >= n) break;
        if (x > i) continue;

        while (x + 1 <= i && s[x + 1] == t[i]) x++;
        if (i - x <= k) move[x] = max(move[x], i);
    }

    vector<vector<int>> moves(k);
    for (int i = 0; i < n; i++) {
        if (move[i] - i <= k) {
            for (int j = i + 1; j <= move[i]; j++) {
                moves[j - i - 1].push_back(j);
            }
        }
    }

    vector<string> changed;
    changed.push_back(s);
    for (int i = 0; i < k; i++) {
        string cur = changed.back();
        if (cur == t) break;
        for (auto ind : moves[i]) {
            cur[ind] = changed.back()[ind - 1];
        }
        changed.push_back(cur);
        if (cur == t) break;
    }
    return changed;
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s, t;
    cin >> s >> t;

    int low = 0, high = k;
    int ans = k + 1;
    vector<string> best;
    best.push_back(s);
    while (low <= high) {
        int mid = (low + high) / 2;
        vector<string> res = check(n, mid, s, t);
        if ((int)res.size() <= k + 1 && res.back() == t) {
            ans = min(ans, (int)res.size() - 1);
            best = res;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (best.back() != t) {
        printf("-1\n");
    } else {
        k = (int)best.size() - 1;
        printf("%lld\n", k);
        for (int i = 1; i <= k; i++) {
            cout << best[i] << "\n";
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
