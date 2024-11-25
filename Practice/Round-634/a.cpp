#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		int ans;
		if (n%2==0) 
			ans=n/2-1;
		else 
			ans=n/2;	
		printf("%d\n",ans);
	}
}
 