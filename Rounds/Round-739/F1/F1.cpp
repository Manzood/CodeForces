#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

string int_to_string (int n) {
    string ret;
    while (n) {
        ret += (n % 10) + '0';
        n /= 10;
    }
    reverse (ret.begin(), ret.end());
    return ret;
}

int string_to_int (string s) {
    int ret = 0;
    int n = s.size();
    int mult = 1;
    for (int i = n - 1; i >= 0; i--) {
        ret += (s[i] - '0') * mult;
        mult *= 10;
    }
    return ret;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        string num = int_to_string (n);
        // calculate answer for k = 1
        int ans = 0;
        int temp = 1;
        int val1 = 0;
        for (int i = 0; i < (int) num.size(); i++) {
            val1 += temp;
            temp *= 10;
        }

        for (int i = 1; i <= 9; i++) {
            if (val1 * i >= n) {
                ans = val1 * i;
                break;
            }
        }

        // now check for k == 2

        if (k == 2) {
            for (int b = 1; b <= 9; b++) {
                for (int a = 0; a < b; a++) {
                    string ans2;
                    int ind = 0;

                    while (ind < (int) num.size() && (num[ind] == a + '0' || num[ind] == b + '0')) {
                        ans2 += num[ind];
                        ind++;
                    }

                    if (ind < (int) num.size()) {
                        if (num[ind] - '0' < a) {
                            ans2 += a + '0';
                        } else if (num[ind] - '0' < b) {
                            ans2 += b + '0';
                        } else {
                            // impossible for this a and b
                            bool found = false;

                            for (int i = (int) ans2.size() - 1; i >= 0; i--) {
                                if (ans2[i] == a + '0') {
                                    ans2[i] = b + '0';
                                    for (int j = i + 1; j < (int) ans2.size(); j++) {
                                        ans2[j] = a + '0';
                                    }
                                    found = true;
                                    break;
                                }
                            }

                            if (!found) continue;
                        }
                    }


                    for (int i = (int) ans2.size(); i < (int) num.size(); i++) {
                        ans2 += a + '0';
                    }
                    // debug (ans2);
                    // if (a == 0 && b == 1) debug (ans2);

                    if (string_to_int (ans2) < ans) {
                        ans = string_to_int (ans2);
                    }
                }
            }
        }

        printf("%lld\n", ans);
    }
}
