#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int check(vector <vector <int> > a,int n)
{
	int pos=0;
	for (int i=0;i<n-1;i++)
	{
		if (a[i+1][pos]==0)
		{
			if (pos==0)
				pos=1;
			else
				pos=0;
			if (a[i][pos]==0 || a[i+1][pos]==0)
				return 0;
		}
	}
	return 1;
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	vector <vector <int> > a(n);
	for (int i=0;i<n;i++)
	{
		a[i].push_back(1);
		a[i].push_back(1);
	}
	int r,c,ans;
	for (int i=0;i<q;i++)
	{
		scanf("%d%d",&r,&c);
		r--;
		c--;
		if (a[c][r]==1)
			a[c][r]=0;
		else
			a[c][r]=1;
		ans=check(a,n);
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
}