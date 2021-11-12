#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        bool sorted = false;
        vector <vector <int>> ans;
        while (!sorted) {
            // find anything out of place
            // debug ("here");
            bool found = false;
            int start = 0;
            int end = n - 1;
            vector <int> ones, zeroes;
            while (start < end) {
                while (s[start] != '1' && start < n) {
                    start++;
                }
                while (s[end] != '0' && end >= 0) {
                    end--;
                }
                if (start < end) {
                    ones.push_back (start);
                    zeroes.push_back (end);
                    start++;
                    end--;
                    found = true;
                }
            }
            // debug (ones.size());
            // debug (zeroes.size());
            if (!found) sorted = true;
            vector <int> temp;
            for (auto x: ones) {
                temp.push_back (x + 1);
            }
            for (int i = 0; i < (int) ones.size(); i++) {
                swap (s[ones[i]], s[zeroes[i]]);
            }
            reverse(zeroes.begin(), zeroes.end());
            for (auto x: zeroes) {
                temp.push_back (x + 1);
                // swap them now
            }
            if (temp.size() > 0) ans.push_back (temp);
        }
        printf("%lld\n", (int) ans.size());
        for (int i = 0; i < (int) ans.size(); i++) {
            printf("%lld ", (int) ans[i].size());
            for (int j = 0; j < (int) ans[i].size(); j++) {
                printf("%lld ", ans[i][j]);
            }
            printf("\n");
        }
    }
}
