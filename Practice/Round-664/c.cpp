#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> a(n);
    vector <int> b(m);
    vector <int> ans(n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) 
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) {
        int mi = 0;
        for (int j = 0; j < m; j++) {
            if (j == 0) 
                mi = b[j] & a[i];
            else 
                mi = min(mi, b[j] & a[i]);
        }
        ans[i] = mi;
    }
    int final = 0;
    for (int i = 0; i < n; i++) {
        final |= ans[i];
    }
    printf("%d\n", final);
}