#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

bool check(int a, int b) {
    if (a>b) return true;
    return false;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n,k;
        scanf("%d%d",&n,&k);
        vector <int> a(n);
        vector <int> b(k);
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<k;i++) {
            scanf("%d",&b[i]);
        }
        sort(a.begin(),a.end(),check);
        sort(b.begin(),b.end());
        long long ans=0;
        int current=0;
        for (int i=0;i<k;i++) {
            ans+=a[current];
            //debug(ans);
            current+=b[i]-1;
            ans+=a[current];
            //debug(ans);
            current++;
        }
        cout<<ans<<endl;
    }
}
