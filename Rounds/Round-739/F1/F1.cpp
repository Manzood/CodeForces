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
            int v3 = -1;

            int ind = -1;
            int ind2 = -1;
            for (int i = 1; i < (int) num.size(); i++) {
                if (v2 == -1) {
                    if (num[i] - '0' != v1) {
                        v2 = num[i] - '0';
                        ind2 = i;
                    }
                } else {
                    if (v3 == -1) {
                        if (num[i] - '0' != v1 && num[i] - '0' != v2) {
                            v3 = num[i] - '0';
                            ind = i;
                        }
                    }
                }
            }

            if (v2 == -1 || v3 == -1) {
                ans = num;
            } else {
                if (v3 <= max (v2, v1) || ind != ind2 + 1) {
                    if (v3 <= max (v2, v1)) {
                        if (v3 < min(v2, v1)) {
                            for (int i = 0; i < (int) num.size(); i++) {
                                if (i < ind) {
                                    ans += num[i];
                                } else {
                                    ans += min (v2, v1) + '0';
                                }
                            }
                        } else {
                            // overwrite it with larger num
                            for (int i = 0; i < (int) num.size(); i++) {
                                if (i < ind) {
                                    ans += num[i];
                                } else {
                                    ans += max (v2, v1) + '0';
                                }
                            }
                        }
                    } else {
                        for (int i = 0; i < (int) num.size(); i++) {
                            if (i < ind - 1) {
                                ans += num[i];
                            }
                        }
                    }
                } else {
                    for (int i = 0; i < (int) num.size(); i++) {
                        if (i < ind2) {
                            ans += num[i];
                        } else if (i == ind2) {
                            v2++;
                            ans += v2 + '0';
                        } else {
                            ans += min (v1, v2) + '0';
                        }
                    }

                    // for (int i = 0; i < (int) num.size(); i++) {
                        // if (ans[i] != v1 && ans[i] != v2) ans[i] = v2 + '0';
                    // }
                }
            }
        }

        cout << ans << "\n";
    }
}
