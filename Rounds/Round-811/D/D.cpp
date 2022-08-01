#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string t;
    cin >> t;
    int len = t.size();
    int n;
    scanf("%lld", &n);
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> farthest(len, 0);
    vector<int> which(len, -1);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < n; j++) {
            int tlen = s[j].size();
            string copy = t.substr(i, tlen);
            if (copy == s[j]) {
                if (tlen > farthest[i]) {
                    farthest[i] = tlen;
                    which[i] = j;
                }
            }
        }
    }

    bool possible = true;
    int rightmost = -1;
    int covered = -1;
    int ind = -1;
    int start = -1;
    vector<vector<int>> ans;
    for (int i = 0; i < len; i++) {
        if (farthest[i] > 0 && i + farthest[i] > rightmost) {
            rightmost = i + farthest[i];
            ind = which[i];
            start = i;
        }
        if (i >= covered) {
            if (rightmost <= i) possible = false;
            covered = rightmost;
            ans.push_back({ind + 1, start + 1});
        }
    }
    if (!possible) {
        printf("-1\n");
    } else {
        printf("%lld\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%lld %lld\n", ans[i][0], ans[i][1]);
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
