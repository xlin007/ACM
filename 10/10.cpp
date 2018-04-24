#include <iostream>
#include <algorithm>
#define msxHeigh 10001
using namespace std;
struct{
	int h;
	int len;
}area[102][102];

int length,searchI,searchJ;

void query(int i,int j){
	if(area[i][j].h>area[i+1][j].h){
		length++;
		query(i+1,j);
	}
	if(area[i][j].h>area[i][j+1].h){
		length++;
		query(i,j+1);
	}
	if(area[i][j].h>area[i-1][j].h){
		length++;
		query(i-1,j);
	}
	if(area[i][j].h>area[i][j-1].h){
		length++;
		query(i,j-1);
	}

	if(length>area[searchI][searchJ].len)
	{
		area[searchI][searchJ].len=length;
	}
	length--;
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--){
		int row,column;
		cin>>row>>column;
		for(int i=0;i<=row+1;i++)
		{
			for(int j=0;j<=column+1;j++){
				if(i==0||j==0||i==row+1||j==column+1)
					area[i][j].h=msxHeigh;
				else
					cin>>area[i][j].h;
			    area[i][j].len=0;
			}
		}
		int max=0;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=column;j++){
				length=0;
				searchI=i;
				searchJ=j;
				query(i,j);
				if(area[i][j].len>max)
					max=area[i][j].len;
			}
		}
		cout<<max+1<<endl;
	}
	return 0;
}