 
#include<iostream>
#include<algorithm>
using namespace std;
int x[30],y[30],n,m,i;;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>m;
		for(i=0;i<m;i++)
			cin>>x[i]>>y[i];
		sort(x,x+m);
		sort(y,y+m);
		int sum=0;
		for(i=0;i<m/2;i++)
			sum+=x[m-1-i]-x[i]+y[m-1-i]-y[i];
		cout<<sum<<endl;
	}
	return 0;
}        