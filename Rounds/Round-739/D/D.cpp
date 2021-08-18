#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        string num;
        cin >> num;

        // enumerate all powers of 2 until 10^10
        int val = 1;
        vector <string> powers;

        while (val < 1e18 + 10) {
            int temp = val;
            string ins;

            while (temp) {
                char ch = temp % 10;
                ch += '0';
                ins += ch;
                temp /= 10;
            }

            reverse (ins.begin(), ins.end());
            powers.push_back (ins);
            val *= 2;
        }

        int ans = num.size() + 1;

        for (auto s: powers) {
            // string matching
            int ind = 0;
            int cur = 0;

            for (int i = 0; i < (int) num.size(); i++) {
                if (ind >= (int) s.size()) break;
                if (num[i] == s[ind]) {
                    ind++;
                }
            }

            // ind matches

            cur += s.size() - ind;
            cur += num.size() - ind;

            ans = min (ans, cur);
            // debug (s);
            // debug (num);
            // debug (cur);
        }

        printf("%lld\n", ans);
    }
}
