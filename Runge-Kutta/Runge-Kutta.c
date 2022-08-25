#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES
//三阶龙格库塔
double runge(double a,double b,double y0,int N)
{
    double x=a,y=y0,K1,K2,K3;
    double h=(b-a)/N;
    for(int i=1;i<=N;i++)
    {
        K1=exp(x);
        K2=exp(x+h/2);
        K3=exp(x+3*h/4);
        y=y+h*(2*K1+3*K2+4*K3)/9;
        x+=h;
    }
    return y;
}
int main(void)
{
    double a=0,b=1,y0=1,Y[7],T[7],O[7];
    int N=10,i;
    for(i=0 ;N<=320;i++)
    {
        Y[i]=runge(a,b,y0,N);
        N*=2;
        T[i]=fabs(M_E-Y[i]);
        if(i!=0)
            O[i-1]=log(T[i-1]/T[i])/log(2);
    }
    N=10;
    for(i=0;N<320;i++)
    {
        printf("N=%d 时：y=%.12f error=%.12f order=%.12f\n",N,Y[i],T[i],O[i]);
        N*=2;
    }
    return 0;
}
