#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        int f = -1, s = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != a[n-i-1]) {
                f = a[i];
                s = a[n-i-1];
                break;
            }
        }
        if (f == -1 && s == -1) {
            printf("YES\n");
        } else {
            // delete them
            bool ans = false;
            vector <int> cp1, cp2;
            for (int i = 0; i < n; i++) {
                if (a[i] != f) cp1.push_back (a[i]);
            }
            for (int i = 0; i < n; i++) {
                if (a[i] != s) cp2.push_back (a[i]);
            }
            bool is_palindrome = true;
            for (int i = 0; i < (int) cp1.size(); i++) {
                if (cp1[i] != cp1[(int)cp1.size()-1-i]) {
                    is_palindrome = false;
                }
            }
            if (is_palindrome) {
                ans = true;
            }
            is_palindrome = true;
            for (int i = 0; i < (int) cp2.size(); i++) {
                if (cp2[i] != cp2[(int)cp2.size()-1-i]) {
                    is_palindrome = false;
                }
            }
            if (is_palindrome) {
                ans = true;
            }
            ans ? printf("YES\n") : printf("NO\n");
        }
    }
}
