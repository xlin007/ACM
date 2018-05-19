#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
#define N 102  
#define INF 1e9  
int result[N][N];//保存从i 到 j所需要的最少括号数  
char s[N];  
int Min(int i,int j)  
{  
   if(result[i][j]!=INF)  
      return result[i][j];  
   else  
   {  
      for(int t=i;t<j;t++)  
      {  
         int tempa=Min(i,t);  
         int tempb=Min(t+1,j);  
         //如果第i 和 第j 匹配的话，那么result[i][j]=result[i+1][j-1]  
         if(s[i-1]=='('&&s[j-1]==')'||(s[i-1]=='['&&s[j-1]==']'))  
           result[i][j]=min(result[i][j],result[i+1][j-1]);  
             
           result[i][j]=min(result[i][j],tempa+tempb);  
      }  
      return result[i][j];  
   }  
}  
int main()  
{  
   int n,T,i,j;  
   cin>>T;  
   while(T--)  
   {  
      scanf("%s",s);  
      n=strlen(s);  
      for(i=1;i<=n;i++)  
         for(j=i+1;j<=n;j++)  
         {  
           result[i][j]=INF;  
         }  
      result[n][n]=1;  
      for(i=1;i<n;i++)  
      {  
         result[i][i]=1;  
         result[i+1][i]=0;  
      }  
      cout<<Min(1,n)<<endl;  
    /*  cout<<"************"<<endl; 
      for(i=1;i<=n;i++) 
       { 
 
          for(j=1;j<=n;j++) 
         { 
           cout<<result[i][j]<<" "; 
         } 
         cout<<endl; 
       }*/  
   }  
    return 0;  
}  
