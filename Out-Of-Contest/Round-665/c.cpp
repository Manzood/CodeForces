    #include<bits/stdc++.h>
    using namespace std;
    #define debug(x) cout<<#x<<" = "<<x<<endl;
    #define sz(x) (int) (x).size()

    int main() {
        int t = 1;
        cin >> t;
        while (t--) {
            int n;
            scanf("%d", &n);
            vector <int> a(n);
            vector <int> b(n);
            int m = 1e9+7;
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
                m = min(a[i], m);
                b[i] = a[i];
            }
            sort(b.begin(), b.end());
            bool ans = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i] && a[i] % m != 0) {
                    // debug(a[i]);
                    // debug(b[i]);
                    // debug(__gcd(a[i], b[i]));
                    ans = false;
                }
            }
            if (ans) printf("YES\n");
            else printf("NO\n");
        }
    }