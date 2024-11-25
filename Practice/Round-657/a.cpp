#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d\n", &n);
        string s;
        cin >> s;
        string good = "abacaba";
        bool found = false;
        int count = 0;
        for (int i=0; i<=n-7; i++) {
            bool current = true;
            for (int j=0; j<7; j++) {
                if (s[i+j] != good[j])
                    current = false;
            }
            if (current) {
                found = true;
                count++;
            }
        }
        if (count == 0) {
            for (int i=0; i<=n-7; i++) {
                bool current = true;
                for (int j=0; j<7; j++) {
                    if (s[i+j] != '?' && s[i+j] != good[j]) 
                        current = false;
                }
                if (current) {
                    found = true;
                    for (int j=0; j<7; j++) {
                        if (s[i+j] == '?') s[i+j] = good[j];
                    }
                    break;
                }
            }
        }
        int second = 0;
        for (int i=0; i<=n-7; i++) {
            bool current = true;
            for (int j=0; j<7; j++) {
                if (s[i+j] != good[j]) {
                    current = false;
                }
            }
            if (current) second++;
        }
        // debug(second);
        if (found && count < 2 && second == 1) {
            printf("YES\n");
            for (int i=0; i<n; i++) {
                if (s[i] == '?') printf("z");
                else printf("%c", s[i]);
            }
            printf("\n");
        }
        else printf("NO\n");
    }
}