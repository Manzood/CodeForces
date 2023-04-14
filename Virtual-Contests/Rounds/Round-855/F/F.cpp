#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int converter(vector<int>& t) {
    int val = 0;
    int mult = 1;
    for (int i = 0; i < (int)t.size(); i++) {
        val += t[i] * mult;
        mult *= 3;
    }
    return val;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<string> s(n);
    vector<vector<int>> occurances(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < (int)s[i].size(); j++) {
            occurances[i][s[i][j] - 'a']++;
        }
    }
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // create a value to search for
        vector<int> cur;
        for (int j = 0; j < 26; j++) {
            int val = occurances[i][j];
            if (val > 0) {
                cur.push_back(!(val % 2));
            } else {
                cur.push_back(2);
            }
        }
        for (int j = 0; j < (int)cur.size(); j++) {
            if (cur[j] == 2) {
                vector<int> marked((int)cur.size(), false);
                for (int x = 0; x < (int)cur.size(); x++) {
                    if (x == j) continue;
                    if (cur[x] == 2) {
                        marked[x] = true;
                        cur[x] = 1;
                    }
                }
                int val = converter(cur);
                if (mp.count(val)) {
                    ans += mp[val];
                }
                for (int x = 0; x < (int)cur.size(); x++)
                    if (marked[x]) cur[x] = 2;
            }
        }
        // insert it into the map
        cur.clear();
        for (int j = 0; j < 26; j++) {
            int val = occurances[i][j];
            if (val > 0) {
                cur.push_back(val % 2);
            } else {
                cur.push_back(2);
            }
        }
        for (int j = 0; j < (int)cur.size(); j++) {
            if (cur[j] == 2) {
                vector<int> marked((int)cur.size(), false);
                for (int x = 0; x < (int)cur.size(); x++) {
                    if (x == j) continue;
                    if (cur[x] == 2) {
                        marked[x] = true;
                        cur[x] = 0;
                    }
                }
                int val = converter(cur);
                mp[val]++;
                for (int x = 0; x < (int)cur.size(); x++)
                    if (marked[x]) cur[x] = 2;
            }
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
