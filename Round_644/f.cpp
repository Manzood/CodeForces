#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,m;
		scanf("%d%d",&n,&m);
		vector <string> a(n);
		for (int i=0;i<n;i++) {
			cin>>a[i];
		}
		int changes[2];
		changes[0]=-1;
		changes[1]=-1;
		int count=0;
		bool possible=true;
		//if there are more than 2 unique changes, not possible
		for (int i=1;i<n;i++) {
			for (int j=0;j<m;j++) {
				//up to two indexes where it is differentiated
				if (a[0][j]!=a[i][j]) {
					if (changes[count]==-1) {
						changes[count]=j;
					}
					else {
						if (changes[count]!=j) {
							count++;
							if (count==2) 
								possible=false;
							else 
								changes[count]=j;
						}
					}
				}
			}
		}
		if (possible) {
			count=0;
			char letter='A';
			for (int i=1;i<n && count==0;i++) {
				if (letter=='A') {
					if (a[0][changes[count]]!=a[i][changes[count]]) {
						letter=a[i][changes[count]];
					}
				}
				else {
					if (a[i][changes[count]]!=letter) {
						count++;
					}
				}
			}
			if (count==0) {
				for (int i=0;i<m;i++) {
					if (i==changes[0]) 
						cout<<letter;
					else 
						cout<<a[0][i];
				}
				cout<<endl;
				continue;
			}
			count=1;
			letter='A';
			for (int i=1;i<n && count==1;i++) {
				if (letter=='A') {
					if (a[0][changes[count]]!=a[i][changes[count]]) {
						letter=a[i][changes[count]];
					}
				}
				else {
					if (a[i][changes[count]]!=letter) {
						count++;
						possible=false;
					}
				}
			}
			if (possible) {
				for (int i=0;i<m;i++) {
					if (i==changes[1] && letter!='A') 
						cout<<letter;
					else 
						cout<<a[0][i];
				}
				cout<<endl;
				continue;
			}
		}
		printf("-1\n");
	}
}


