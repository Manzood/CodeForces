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

        bool possible = true;
        vector <string> ans(n);
        int twoscount = 0;

        int f = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '2') twoscount++;
            if (f == -1 && s[i] == '2') f = i;

            for (int j = 0; j < n; j++) {
                ans[i] += '=';
                if (i == j) ans[i][j] = 'X';
            }
        }

        if (twoscount > 0 && twoscount < 3) {
            possible = false;
        }

        if (possible) {
            printf("YES\n");

            for (int i = 0; i < n; i++) {
                if (s[i] == '2') {
                    bool found = false;
                    int ind = 0;

                    for (int j = i + 1; j < n; j++) {
                        if (s[j] == '2') {
                            found = true;
                            ind = j;
                            break;
                        }
                    }

                    if (!found) {
                        ind = f;
                    }

                    ans[i][ind] = '+';
                    ans[ind][i] = '-';
                }
            }

            for (int i = 0; i < n; i++) {
                cout << ans[i] << "\n";
            }
        } else {
            printf("NO\n");
        }
    }
}
