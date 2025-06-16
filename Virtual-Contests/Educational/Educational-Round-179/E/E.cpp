#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    string s;
    cin >> s;

    vector<pair<int, int>> queries(q);
    map<pair<int, int>, int> cnt;
    map<pair<int, int>, multiset<int>> index;

    for (int i = 0; i < q; i++) {
        char x, y;
        cin >> x >> y;
        queries[i] = {x - 'a', y - 'a'};
        cnt[queries[i]]++;
        index[queries[i]].insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (cnt[{1, 0}]) {
                index[{1, 0}].erase(index[{1, 0}].begin());
                cnt[{1, 0}]--;
                s[i] = 'a';
            } else if (cnt[{1, 2}] && cnt[{2, 0}]) {
                auto it1 = index[{1, 2}].begin();
                auto it2 = index[{2, 0}].upper_bound(*it1);
                if (it2 != index[{2, 0}].end()) {
                    cnt[{1, 2}]--;
                    cnt[{2, 0}]--;
                    index[{1, 2}].erase(it1);
                    index[{2, 0}].erase(it2);
                    s[i] = 'a';
                }
            }
        } else if (s[i] == 'c') {
            if (cnt[{2, 0}]) {
                cnt[{2, 0}]--;
                index[{2, 0}].erase(index[{2, 0}].begin());
                s[i] = 'a';
            } else if (cnt[{2, 1}] && cnt[{1, 0}] &&
                       index[{1, 0}].upper_bound(*index[{2, 1}].begin()) !=
                           index[{1, 0}].end()) {
                auto it1 = index[{2, 1}].begin();
                auto it2 = index[{1, 0}].upper_bound(*it1);
                index[{2, 1}].erase(it1);
                index[{1, 0}].erase(it2);

                cnt[{2, 1}]--;
                cnt[{1, 0}]--;
                s[i] = 'a';
            } else if (cnt[{2, 1}]) {
                cnt[{2, 1}]--;
                index[{2, 1}].erase(--index[{2, 1}].end());  // does this work?
                s[i] = 'b';
            }
        }
    }

    cout << s << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
