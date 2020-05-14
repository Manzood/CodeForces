#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		vector <int> prefix(n);
		set <int> elements;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			elements.insert(a[i]);
			if (i==0)
				prefix[i]=a[i];
			else
				prefix[i]=prefix[i-1]+a[i];
		}
		set <int> used;
		int ans=0;
		for (int i=0;i<n;i++) {
			for (int j=i+1;j<n;j++) {
				if (elements.count(prefix[j]-prefix[i])>0) {
					//debug(prefix[j]-prefix[i]);
					if (used.count(prefix[j]-prefix[i])==0) {
						used.insert(prefix[j]-prefix[i]);
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
