#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	int ans=n;
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		if (k>=a[i] && a[i]!=0)
			ans=min(ans,abs(m-i-1));
	}
	cout<<ans*10<<endl;
}