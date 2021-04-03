#include <stdio.h>
#define EPS 1e-8
#define PI 3.141592653
double r, R, H, V;
double cal(double r,double R,double h,double H)
{
    double u = h/H*(R-r) + r;
    return PI/3*(r*r+r*u+u*u)*h;
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%lf%lf%lf%lf",&r,&R,&H,&V);
                double minn=0,maxn=100,mid;
                while(maxn-minn>EPS)
                {
                        mid=(maxn+minn)/2;
                        double cmid=cal(r,R,mid,H);
                        if(cmid<V)
                                minn=mid;
                        else
                                maxn=mid;
                }
                printf("%.6lf\n",mid);
        }
        return 0;
}
