 
//动态规划解题
#include<cstdio>   
#include<string>
#include<iostream>
using namespace std;
int opt[102][102];   
int map[102][102];   
int dir[4][2] = {-1,0,1,0,0,-1,0,1};   
int r,c;   
int w(int a,int b)   
{   
    int i;   
    if(a<1||b<1||a>r||b>c) return 0;        
    if(opt[a][b] != 0) return opt[a][b];   
    else  
    {   
        for(i=0;i<4;i++)   
            if( map[a+dir[i][1]][b+dir[i][0]] < map[a][b]&&   
                w(a+dir[i][1],b+dir[i][0]) > opt[a][b] )       
                   opt[a][b] = w(a+dir[i][1],b+dir[i][0]);            
        return ++opt[a][b];   
    }   
}    
int main(void)   
{   
    int max,i,j;  
	int n;
	scanf("%d",&n);
    while(n--)   
    {   
		scanf("%d%d",&r,&c);
        for( i = 1 ; i <= r ; i++ )   
            for( j = 1 ; j <= c ; j++ )   
                scanf("%d",&map[i][j]);             
        for(int i=0;i<102;i++)
			for(int j=0;j<102;j++)
				opt[i][j]=0;
        max = 0;   
        for( i = 1 ; i <= r ; i++ )   
            for( j = 1 ; j <= c ; j++ )   
                if(w(i,j) > max) max = w(i,j);                      
        printf("%d\n",max);   
    }     
    return 0;   
} 
        