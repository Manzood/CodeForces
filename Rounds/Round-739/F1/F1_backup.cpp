#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld", &n);
        // scanf("%lld%lld", &n, &k);
        // COMMENT THE LINE BELOW OUT BEFORE SUBMITTING
        k = 2;

        string num;
        int temp = n;

        string ans;

        while (temp) {
            char ch = temp % 10;
            ch += '0';
            num += ch;
            temp /= 10;
        }
        reverse (num.begin(), num.end());

        if (k == 1) {
            int val = num[0] - '0';

            bool gt = false;
            for (int i = 1; i < (int) num.size(); i++) {
                int tval = num[i] - '0';
                if (tval > val) gt = true;
            }

            for (int i = 0; i < (int) num.size(); i++) {
                if (gt) {
                    ans += val + 1 + '0';
                } else {
                    ans += val + '0';
                }
            }
        } else {
            int v1 = num[0] - '0';
            int v2 = -1;

            bool gt = false;
            bool noncompliant = false;
            int ind = -2;

            for (int i = 1; i < (int) num.size(); i++) {
                int tval = num[i] - '0';

                if (v2 == -1) {
                    if (tval != v1) {
                        v2 = tval;
                        ind = i;
                    }
                } else {
                    if (tval != v1 && tval != v2) noncompliant = true;
                    if (tval > v2 && ind == i - 1) {
                        gt = true;
                    }
                }
            }

            if (!noncompliant) {
                ans = num;
            } else {
                ans += v1 + '0';
                // if (gt) ans += v2 + 1 + '0';
                // else ans += v2 + '0';

                if (gt) {
                    for (int i = 1; i < (int) num.size(); i++) {
                        if (gt) {
                            if (num[i] - '0' == v1) ans += v1 + '0';
                            else {
                                v2++;
                                ans += v2 + '0';
                                gt = false;
                            }
                        } else {
                            ans += min(v1, v2) + '0';
                        }
                    }
                } else {

                    bool is_gt = false;
                    for (int i = 1; i < (int) num.size(); i++) {
                        // int val = max ((int) num[i] - '0', min(v1, v2));
                        if (num[i] - '0' < min (v1, v2)) is_gt = true;
                        int val = v1;
                        if (!is_gt && num[i] - '0' > min (v1, v2)) {
                            val = max (v1, v2);
                            is_gt = true;
                        } else {
                            val = min (v1, v2);
                        }
                        ans += val + '0';
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}
