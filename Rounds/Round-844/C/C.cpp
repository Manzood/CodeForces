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
    vector<int> factors;
    int tmp = 1;
    for (; tmp * tmp < n; tmp++) {
        if (n % tmp == 0) {
            factors.push_back(tmp);
            factors.push_back(n / tmp);
        }
    }
    if (tmp * tmp == n) factors.push_back(tmp);
    vector<pair<int, char>> occurences(26, {0, 'a'});
    for (int i = 0; i < 26; i++) occurences[i].second = (char)i + 'a';
    for (auto x : s) occurences[x - 'a'].first++;
    sort(occurences.begin(), occurences.end());

    int ans = (int)1e9 + 7;
    auto best = occurences;
    for (auto cnt : factors) {
        if (26 * cnt < n) continue;
        auto temp = occurences;
        int cur = 0, tot = 0;
        int ind;
        for (int i = 25; i >= 0; i--) {
            ind = i;
            if (temp[i].first > cnt) {
                cur += temp[i].first - cnt;
                temp[i].first = cnt;
                tot += temp[i].first;
            } else {
                break;
            }
        }
        int reduced = cur;
        while (tot < n && ind >= 0) {
            int diff = cnt - temp[ind].first;
            temp[ind].first = cnt;
            tmp = diff;
            diff -= min(reduced, tmp);
            reduced -= min(reduced, tmp);
            if (reduced == 0) cur += diff;
            tot += temp[ind--].first;
        }
        while (ind >= 0) {
            temp[ind--].first = 0;
        }
        if (cur < ans) {
            ans = cur;
            best = temp;
        }
        // debug(tot);
        // debug(occurences);
        // debug(temp);
        assert(tot == n);
    }

    vector<bool> used(n, false);
    vector<int> cnt(26, 0), req(26, 0);
    for (auto x : best) req[x.second - 'a'] = x.first;
    for (int i = 0; i < n; i++) {
        if (cnt[s[i] - 'a'] < req[s[i] - 'a']) {
            used[i] = true;
            cnt[s[i] - 'a']++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            for (int j = 0; j < 26; j++) {
                if (cnt[j] < req[j]) {
                    cnt[j]++;
                    s[i] = (char)j + 'a';
                    break;
                }
            }
        }
    }
    printf("%lld\n", ans);
    cout << s << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
