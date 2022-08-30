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
    int score[3] = {0, 0, 0};
    vector<vector<string>> input(3, vector<string>());
    vector<map<string, int>> mp(3, map<string, int>());
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            string a;
            cin >> a;
            input[j].push_back(a);
            mp[j][a]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int word = 0; word < n; word++) {
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (mp[j][input[i][word]]) cnt++;
            }
            if (cnt == 1) {
                score[i] += 1;
            } else if (cnt == 0) {
                score[i] += 3;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     map<string, int> mp;
    //     vector<string> s(3);
    //     // cin >> s[0] >> s[1] >> s[2];
    //     s[0] = input[0][i];
    //     s[1] = input[1][i];
    //     s[2] = input[2][i];
    //     // debug(s);
    //     mp[s[0]]++;
    //     mp[s[1]]++;
    //     mp[s[2]]++;
    //     for (int j = 0; j < 3; j++) {
    //         if (mp[s[j]] == 1) {
    //             score[j] += 3;
    //         } else if (mp[s[j]] == 2) {
    //             score[j] += 1;
    //         }
    //     }
    //     if (test == 2) debug(mp);
    // }
    printf("%lld %lld %lld\n", score[0], score[1], score[2]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
