 
#include <stdio.h>
#include <math.h>
double g(double x1,double y1,double x2,double y2,double x3,double y3){  
    return (x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)/2;
    } 
int main(){
    int n,m;  
    scanf("%i",&n);   
    while(n--){   
        scanf("%i",&m);  
        m-=2;   
        double x1,y1,x,y,xn,yn,gsx=0,gsy=0,s=0,cs=0;   
        scanf("%lf%lf%lf%lf",&x1,&y1,&x,&y);   
        while(m--){
            scanf("%lf%lf",&xn,&yn);    
            s+=(cs=g(x1,y1,x,y,xn,yn));   
            gsx+=(x1+x+xn)*cs/3;    
            gsy+=(y1+y+yn)*cs/3;    
            x=xn;    
            y=yn;   
        }   
        printf("%.3f %.3f\n",fabsf(s),(s==0?0.0:fabsf((gsx+gsy)/s)));
    } 
}        