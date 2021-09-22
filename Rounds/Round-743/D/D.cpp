#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <int> solveoddarray (vector <int>& a, int start, int end) {
    vector <int> ans;
    // it's an odd length array with an even number of 1s
    for (int i = start; i <= end - 2; i+=2) {
        ans.push_back(i + 1);
    }
    for (int i = end - 4; i >= start; i-=2) {
        ans.push_back(i + 1);
    }
    return ans;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            sum += a[i];
        }

        bool possible = true;
        vector <int> ans;
        if (sum % 2 == 0) {
            if (n % 2 == 1) {
                ans = solveoddarray(a, 0, n - 1);
            } else {
                // try to have an even number of ones at an array of odd length, to remove it
                // then remove the rest of the array
                if (a[0] == 0) {
                    ans = solveoddarray(a, 1, n - 1);
                } else {
                    int s = 0;
                    possible = false;
                    for (int i = 0; i < n; i++) {
                        s += a[i];
                        vector <int> t1;
                        if (s % 2 == 0 && i % 2 == 0) {
                            ans = solveoddarray (a, 0, i);
                            t1 = solveoddarray (a, i + 1, n - 1);
                            for (int j = 0; j < (int) t1.size(); j++) {
                                ans.push_back (t1[j]);
                            }
                            possible = true;
                            break;
                        }
                    }
                }
            }
        } else {
            possible = false;
        }
        if (!possible) {
            printf("NO\n");
        } else {
            printf("YES\n");
            printf("%lld\n", (int) ans.size());
            if ((int) ans.size() > 0) {
                for (int i = 0; i < (int) ans.size(); i++) {
                    printf("%lld ", ans[i]);
                }
                printf("\n");
            }
        }
    }
}
